// fallout/interface/menus/loadingmenu.cpp: LoadingMenu, BSAudio, LoadingMenuStandIn, LoadingMenuX and more (71 functions)

#include <new>
#include <cctype>
#include "fnv/decl/AnimTile.h"
#include "fnv/decl/BEC16D0MoviePlayerThread.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/DecalStub.h"
#include "fnv/decl/FUN_004077c0_shell.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_0041fd00_shell.h"
#include "fnv/decl/FUN_00424940_shell.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_00442550_shell.h"
#include "fnv/decl/FUN_00450410_Class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00461070_shell.h"
#include "fnv/decl/FUN_004ed8c0_shell.h"
#include "fnv/decl/FUN_00526ac0_shell.h"
#include "fnv/decl/FUN_005a7110_shell.h"
#include "fnv/decl/FUN_005a7130_shell.h"
#include "fnv/decl/FUN_005bb4d0_shell.h"
#include "fnv/decl/FUN_005ec330_shell.h"
#include "fnv/decl/FUN_00678ce0_shell.h"
#include "fnv/decl/FUN_00759450_shell.h"
#include "fnv/decl/FUN_0078cf10_Class.h"
#include "fnv/decl/FUN_00865e50_shell.h"
#include "fnv/decl/FUN_00952b30_Class.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a07530_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00a20cc0_t.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00ad7230_shell.h"
#include "fnv/decl/FUN_00ba2fa0_C.h"
#include "fnv/decl/FUN_00ec17c0_Class.h"
#include "fnv/decl/FileMatchList.h"
#include "fnv/decl/FontManager.h"
#include "fnv/decl/ListStandIn.h"
#include "fnv/decl/LoadScreenTypeData_FUN.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MagicCaster_shell.h"
#include "fnv/decl/NiTPointerListBase.h"
#include "fnv/decl/PatrolActorPackageData.h"
#include "fnv/decl/S1740.h"
#include "fnv/decl/S_0082f1f0_Lock.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/SemaphoreWaitReceiver.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TESObjectCELL.h"
#include "fnv/decl/TESTexLoader.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/ThreadCoordinator_ba2f30.h"
#include "fnv/decl/ThreadStageSignalDetail__RenderingStageController.h"
#include "fnv/decl/TileImage.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Twin_00639b40.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_004a03c0__DD.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_00575d10__FUN_00575d10_shell.h"
#include "fnv/decl/fnv_00713fb0__MenuMgr.h"
#include "fnv/decl/fnv_008454f0__FUN_008454f0.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/decl/fnv_00865df0__FUN_00865df0_holder.h"
#include "fnv/decl/fnv_0087f9f0__FUN_0087f9f0_shell.h"
#include "fnv/decl/fnv_009a4320__FUN_009a4320_arr.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/decl/fnv_00ec25e0__FUN_00ec25e0_cls.h"
#include "fnv/decl/s44b130__Lock.h"
#include "fnv/decl/sa040a0__Owner.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_00438000.h"
#include "fnv/symbols_0043c000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_0044a000.h"
#include "fnv/symbols_00452000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004a0000.h"
#include "fnv/symbols_004af000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005a0000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005c2000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_00713000.h"
#include "fnv/symbols_00715000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00761000.h"
#include "fnv/symbols_00771000.h"
#include "fnv/symbols_00775000.h"
#include "fnv/symbols_00788000.h"
#include "fnv/symbols_0078a000.h"
#include "fnv/symbols_0078b000.h"
#include "fnv/symbols_0078d000.h"
#include "fnv/symbols_0082f000.h"
#include "fnv/symbols_00830000.h"
#include "fnv/symbols_00890000.h"
#include "fnv/symbols_009e3000.h"
#include "fnv/symbols_00a04000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a61000.h"
#include "fnv/symbols_00ba3000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_01015000.h"
#include "fnv/symbols_0101d000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_01074000.h"
#include "fnv/symbols_011a0000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011c6000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f4000.h"
#include "fnv/symbols_0126f000.h"
#include "loadingmenu_packet.h"
class BSSystemUtility
{
  public:
    static int s_iUpdateEnabled;
    static BSSystemUtility* ms_pSystemUtility;
public:
    static void GetRandomGenerator();
};

// @fnv 0x0078d2d0
void LoadingMenu::HideTile()
{
    if (BSSystemUtility::s_iUpdateEnabled)
        reinterpret_cast<LoadingMenu*>(BSSystemUtility::s_iUpdateEnabled)
            ->SetTileVisible((LoadingMenu::TileIndex)0, false);
}

// Sets or clears the bit at index in usFlags according to set.
// @fnv 0x00458080
void LoadingMenu::SetFloatFlag(int index, bool set)
{
    if (set)
        usFlags |= (1 << index);
    else
        usFlags &= ~(1 << index);
}

// @fnv 0x0078cbd0
void LoadingMenu::SetTileVisible(LoadingMenu::TileIndex tileIndex, bool doSwap)
{
    for (int i = 0; i < 38; ++i)
    {
        reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[i]))->FUN_00a012d0(0xFA3, (float)(i == (int)tileIndex || (tileIndex == 0 && (i == 32 || i == 33))), false);
    }
    SetFloatFlag(6, doSwap);
}

class CountingSemaphore
{
  public:
    int iCount;
    void* hSemaphore;
    int m_iMaximumCount;
    CountingSemaphore();
    ~CountingSemaphore();
    void Wait();
};

class LoadingMenuThread : public BSThread
{
  public:
    CountingSemaphore m_kFirstSemaphore;
    CountingSemaphore m_kSecondSemaphore;
    volatile bool m_bFirstThreadFlag;
    volatile bool m_bSecondThreadFlag;
    volatile bool m_bThirdThreadFlag;
    LoadingMenuThread();
    unsigned int ThreadProc();
};

// Initializes the loading menu thread: clears the three flags, sets its name, initializes the stack, and sets priority.
// @fnv 0x0078d2f0
LoadingMenuThread::LoadingMenuThread() : BSThread(), m_kFirstSemaphore(), m_kSecondSemaphore()
{
    m_bFirstThreadFlag = false;
    m_bSecondThreadFlag = false;
    m_bThirdThreadFlag = false;
    SetName("LoadingMenu");
    Initialize((BSThread::StackSize)0x4000, "LoadingMenu", false);
    SetSchedulingPriority(5);
    SetThreadPriority(-1);
}

// @fnv 0x0078cfc0
void LoadingMenu::UpdateLoadingScreenThread()
{
    if (BSSystemUtility::s_iUpdateEnabled && BSSystemUtility::ms_pSystemUtility &&
        ::FUN_008905f0((bool *)(reinterpret_cast<LoadingMenuThread*>(BSSystemUtility::ms_pSystemUtility))) &&
        !reinterpret_cast<LoadingMenuThread*>(BSSystemUtility::ms_pSystemUtility)->m_bFirstThreadFlag)
    {
        reinterpret_cast<LoadingMenuThread*>(BSSystemUtility::ms_pSystemUtility)->SetThreadPriority(1);
        reinterpret_cast<LoadingMenuThread*>(BSSystemUtility::ms_pSystemUtility)->m_bFirstThreadFlag = true;
        reinterpret_cast<::SemaphoreWaitReceiver *>(&(reinterpret_cast<LoadingMenuThread*>(BSSystemUtility::ms_pSystemUtility)->m_kSecondSemaphore))->FUN_004424e0();
    }
}

// @fnv 0x00717740
void LoadingMenu::SetLoadingScreenVisible(int visible)
{
    NiGeometry* object;
    RgbaColor* pColors = ((::RgbaColor *)(reinterpret_cast<::FUN_0045cd60_shell *>((reinterpret_cast<NiGeometryData*>(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_0045cd60()));
    NiNode* node = pColors ? ((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((pColors))->FUN_0056c7f0())) : 0;
    object = 0;
    // object is deliberately initialized after obtaining the node.
    if (node)
    {
        object = reinterpret_cast<NiGeometry*>(((::NiAVObject *)(reinterpret_cast<::S_FUN_0045bc00 *>((node))->FUN_0045bc00(0))));
        if (object)
        {
            NiProperty* property = ((::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((object))->FUN_00a59d30(FUN_004af350())));
            if (property)
                reinterpret_cast<::DecalStub *>((property))->FUN_0068c9f0((float)visible);
        }
    }
}

// Computes a delay from one of three sources depending on state, converts it to milliseconds, and stores the next tip time as the current tick plus that delay.
// @fnv 0x0078abd0
void LoadingMenu::UpdateLoadingScreenTip()
{
    float delay = 0.0f;
    if (FUN_0070edf0())
        delay = reinterpret_cast<::FUN_00450410_Class *>(&(g_011da190))->FUN_00450410();
    else if (DAT_011a0294)
        delay = reinterpret_cast<::FUN_00450410_Class *>(&(g_011da158))->FUN_00450410();
    else
        delay = reinterpret_cast<::FUN_00450410_Class *>(&(g_011da1a0))->FUN_00450410();
    nextTipTime = ((unsigned int)(::FUN_00457fe0())) + (unsigned int)(delay * 1000.0);
}

// @fnv 0x0078ab20
bool LoadingMenu::IsLoadScreenValid(TESLoadScreen* screen)
{
    bool valid = screen && screen->GetFormType() == FormLoadScreen;
    for (BSSimpleList<BGSPerkEntry*>* entry = &candidates; valid && entry && ((::BGSPerkEntry *)(new ((void *)(entry)) ::Vec3())); entry = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((entry))->FUN_00726070())))
    {
        valid = FUN_00408b20(((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(screen->fullName))->FUN_00408da0())), ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&(((::BGSPerkEntry *)(new ((void *)(entry)) ::Vec3()))->fullName))->FUN_00408da0()))) != 0;
    }
    return valid;
}

// @fnv 0x0078aec0
void LoadingMenu::RefreshLoadingScreen()
{
    if (!::g_BGSSaveLoadGame || !reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((::g_BGSSaveLoadGame))->FUN_0042ce10())
        FUN_0078d670();
    reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[10]))->FUN_00a012d0(0x1004, DAT_011da16c, true);
    m_pTiles[10]->Set(0x1005, DAT_011da170);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[3]))->FUN_00a01350(0xfc4,
                     (char *)(g_011da168.objective ? reinterpret_cast<::FUN_005ec330_shell *>((g_011da168.objective))->GetPromptText()
                                          : ((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d1f8c)))->GetMenuTitle()))),
                     true);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[14]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d40f0)))->GetMenuTitle()))), true);
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[15]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d2358)))->GetMenuTitle()))), true);
}

// Picks random load screens from array into candidates until the candidate count reaches the game-setting count, removing each picked entry.
// @fnv 0x0078adc0
void LoadingMenu::SelectLoadScreens(BSSimpleArray<TESLoadScreen*, 1024>& aLoadScreens)
{
    unsigned int count = ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)(reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011da138)))))->u;
    if (GetFloat(5))
        count = ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)(reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011da124)))))->u;
    else if (extraCandidates && !((bool)(::FUN_0078a930())))
        count = FUN_0042f5a0(count, ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)(reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011da108)))))->u);
    unsigned int maximum = reinterpret_cast<BSSimpleList<BGSMusicType::MusicTrack*>*>(&candidates)->ItemsInList();
    while (maximum < count && ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<BSSimpleArray<ParentSpaceNode, 1024>*>(&aLoadScreens)))->GetName())))
    {
        unsigned int index =
            FUN_005a00a0(((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((reinterpret_cast<BSSimpleArray<ParentSpaceNode, 1024>*>(&aLoadScreens)))->GetName())));
        if (IsLoadScreenValid(
                reinterpret_cast<TESLoadScreen*>(reinterpret_cast<NiFormArray*>(&aLoadScreens)->FUN_00877a30(index))))
        {
            reinterpret_cast<::Callees *>((reinterpret_cast<BSSimpleList<ScriptVariableInfo*>*>(&candidates)))->FUN_00905820((void *)&(reinterpret_cast<ScriptVariableInfo* const&>(
                    reinterpret_cast<NiFormArray*>(&aLoadScreens)->FUN_00877a30(index))));
            ++maximum;
        }
        reinterpret_cast<::fnv_009a4320::FUN_009a4320_arr *>(&(aLoadScreens))->FUN_009a4320(index, 1);
    }
}

// Reads quest, objective, and load-screen data from the buffer, stores them in globals, and updates the loading menu UI.
// @fnv 0x0078d770
void LoadingMenu::LoadGame(BGSLoadGameBuffer* buffer)
{
    TESQuest* b = 0;     // saved quest
    unsigned int c = 0;  // saved objective ID
    b = dynamic_cast<TESQuest*>(::FUN_004839c0(reinterpret_cast<::fnv_008648a0::FUN_008648a0_t *>((buffer))->FUN_008648a0()));
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&c), 4);
    g_011da168.objective = b ? b->GetObjective(c) : 0;
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&DAT_011da16c), 4);
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&DAT_011da170), 4);
    if ((unsigned int)DAT_011da170 >= ((::SETTING_VALUE *)&(::FUN_0043d4d0((int *)(reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011d0c60)))))->u)
        DAT_011da16c = 0.0f;
    bool a = false;  // location-specific screens only
    reinterpret_cast<::fnv_00864980::FUN_00864980_shell *>((buffer))->FUN_00864980((::fnv_00864980::NiQuaternion *)(void *)(&a), 1);
    ::FUN_005c25e0(a);
    if (BSSystemUtility::s_iUpdateEnabled)
    {
        reinterpret_cast<LoadingMenu*>(BSSystemUtility::s_iUpdateEnabled)->m_pTiles[11]->Set(0xfa3, 1);
        reinterpret_cast<LoadingMenu*>(BSSystemUtility::s_iUpdateEnabled)->SetFloatFlag(8, false);
    }
    FUN_004581c0(true);
}

// @fnv 0x0078afc0
void LoadingMenu::UpdateLoadScreen(TESLoadScreen* screen, float alpha, int mode)
{
    if (!GetFloat(6))
        return;
    if (!screen)
    {
        if (currentCandidate)
            screen = reinterpret_cast<TESLoadScreen*>(((::BGSPerkEntry *)(new ((void *)(currentCandidate)) ::Vec3())));
        else
            screen = reinterpret_cast<TESLoadScreen*>(((::BGSPerkEntry *)(new ((void *)&(candidates)) ::Vec3())));
        if (!screen)
            return;
    }
    if (reinterpret_cast<BGSCameraPath*>(screen)->GetPrevPath())
    {
        Tile** tiles = 0;
        int type = reinterpret_cast<::FUN_005a7130_shell *>((screen))->FUN_005a7130();
        switch (type)
        {
        case 4:
            tiles = reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0xd0);
            FUN_0078b100(alpha, mode);
            break;
        case 3:
            tiles = reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0xf4);
            FadeSlideTiles(alpha, mode);
            break;
        case 1:
            tiles = reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0xe8);
            UpdateLoadingTiles(alpha, mode);
            break;
        case 2:
            tiles = reinterpret_cast<Tile**>(reinterpret_cast<char*>(this) + 0xdc);
            UpdateTiles(alpha, mode);
            break;
        }
    }
}

// @fnv 0x004581c0
void __cdecl FUN_004581c0(bool abOn)
{
    if (BSSystemUtility::s_iUpdateEnabled)
    {
        reinterpret_cast<LoadingMenu*>(BSSystemUtility::s_iUpdateEnabled)->SetFloatFlag(3, abOn);
    }
}

struct SubObj
{
};
struct LM2
{
    char pad[0x6c];
    int a;
    int b;
    char pad2[0xd0 - 0x74];
    SubObj s;
    void FUN_00788f30();
};
// Calls s.FUN_004ed900, then passes &a and &b to s.FUN_004ed8c0 in turn.
// @fnv 0x00788f30
void LM2::FUN_00788f30()
{
    reinterpret_cast<::NiTPointerListBase *>(&(s))->FUN_004ed900();
    reinterpret_cast<::FUN_004ed8c0_shell *>(&(s))->FUN_004ed8c0(&a);
    reinterpret_cast<::FUN_004ed8c0_shell *>(&(s))->FUN_004ed8c0(&b);
}

struct FUN_Sub
{
};
// Calls FUN_004ed900 on the FUN_Sub at self+0xdc, then FUN_004ed8c0 with self+0x94, self+0x34 and self+0x60.
// @fnv 0x00788f80
void FUN_00788f80(char* self)
{
    reinterpret_cast<::NiTPointerListBase *>((((FUN_Sub*)(self + 0xdc))))->FUN_004ed900();
    reinterpret_cast<::FUN_004ed8c0_shell *>((((FUN_Sub*)(self + 0xdc))))->FUN_004ed8c0((int *)(void *)(self + 0x94));
    reinterpret_cast<::FUN_004ed8c0_shell *>((((FUN_Sub*)(self + 0xdc))))->FUN_004ed8c0((int *)(void *)(self + 0x34));
    reinterpret_cast<::FUN_004ed8c0_shell *>((((FUN_Sub*)(self + 0xdc))))->FUN_004ed8c0((int *)(void *)(self + 0x60));
}

struct M788
{
};
struct S788
{
    char pad[0xe8];
    M788 m;
    void FUN_00788fe0();
};
// Calls m.FUN_004ed900, then passes six member addresses (offsets 0x68, 0x98, 0x9c, 0x64, 0x50, 0xa0) to m.FUN_004ed8c0.
// @fnv 0x00788fe0
void S788::FUN_00788fe0()
{
    reinterpret_cast<::NiTPointerListBase *>(&(m))->FUN_004ed900();
    reinterpret_cast<::FUN_004ed8c0_shell *>(&(m))->FUN_004ed8c0((int *)(void *)((char*)this + 0x68));
    reinterpret_cast<::FUN_004ed8c0_shell *>(&(m))->FUN_004ed8c0((int *)(void *)((char*)this + 0x98));
    reinterpret_cast<::FUN_004ed8c0_shell *>(&(m))->FUN_004ed8c0((int *)(void *)((char*)this + 0x9c));
    reinterpret_cast<::FUN_004ed8c0_shell *>(&(m))->FUN_004ed8c0((int *)(void *)((char*)this + 0x64));
    reinterpret_cast<::FUN_004ed8c0_shell *>(&(m))->FUN_004ed8c0((int *)(void *)((char*)this + 0x50));
    reinterpret_cast<::FUN_004ed8c0_shell *>(&(m))->FUN_004ed8c0((int *)(void *)((char*)this + 0xa0));
}

namespace fnv_00789080 {
struct SubObj
{
};
struct LM3
{
    char pad[0xb0];
    int a;
    int b;
    char pad2[0xf4 - 0xb8];
    SubObj s1;
    char pad3[0x100 - 0xf5];
    SubObj s2;
    void FUN_00789080();
};
// Calls FUN_004ed900 then FUN_004ed8c0 on s1 with &a and on s2 with &b.
// @fnv 0x00789080
void LM3::FUN_00789080()
{
    reinterpret_cast<::NiTPointerListBase *>(&(s1))->FUN_004ed900();
    reinterpret_cast<::FUN_004ed8c0_shell *>(&(s1))->FUN_004ed8c0(&a);
    reinterpret_cast<::NiTPointerListBase *>(&(s2))->FUN_004ed900();
    reinterpret_cast<::FUN_004ed8c0_shell *>(&(s2))->FUN_004ed8c0(&b);
}
}  // namespace fnv_00789080

struct FUN_0078a1c0_shell
{
    char pad[0x222];
    unsigned short usFlags;
    void ToggleFlagBit(int aBit);
};

// Toggles the bit at position aBit in usFlags using XOR with 1 << aBit.
// @fnv 0x0078a1c0
void FUN_0078a1c0_shell::ToggleFlagBit(int aBit)
{
    usFlags ^= 1 << aBit;
}

struct NiControllerSequence
{
};

struct FUN_0078a1f0_this
{
    char pad[0x3c];
    NiControllerSequence* pSequence;
};

// Returns true if pSequence is set and its GetState() equals 1.
// @fnv 0x0078a1f0
bool FUN_0078a1f0(FUN_0078a1f0_this* pThis)
{
    return pThis->pSequence && ((int)(reinterpret_cast<::LowProcess *>((pThis->pSequence))->GetActiveCombatTarget())) == 1;
}

struct FUN_0078a230_shell : public LoadingMenu
{
    void FUN_0078a230();
};

struct Dummy_00a20ed0
{
};

// Calls UpdateAnimation on the object at offset 0x54 with -1.0f and 0.
// @fnv 0x0078a230
void FUN_0078a230_shell::FUN_0078a230()
{
    reinterpret_cast<::AnimTile *>(((*reinterpret_cast<Dummy_00a20ed0**>(&this->m_pTiles[11]))))->UpdateAnimation(-1.0f, 0);
}


// @fnv 0x0078a260
const char* __cdecl GetGameSettingString(int index)
{
    return ((const char *)(reinterpret_cast<::StartMenu *>(((*(*reinterpret_cast<SettingT_GameSettingCollection_ ** (*)[]>(&::DAT_011c6d50))[index])))->GetMenuTitle()));
}

// Returns the value pointed to by p, then increments that value by one.
// @fnv 0x0078a910
int __cdecl PostIncrementInt(int* piValue)
{
    int old = *piValue;
    *piValue = *piValue + 1;
    return old;
}

class TESForm_Ex
{
  public:
    virtual void vfn_0();
    virtual void vfn_1();
    virtual void vfn_2();
    virtual void vfn_3();
    virtual ~TESForm_Ex();
};


// @fnv 0x0078a940
void FUN_0078a940(char* this_ptr)
{
    for (void* pIter = this_ptr + 0x1d0; pIter && *((::TESForm_Ex **)(new ((void *)(pIter)) ::Vec3())); pIter = reinterpret_cast<::Callees *>((pIter))->FUN_00726070())
    {
        if (reinterpret_cast<::FUN_004077c0_shell *>((void *)(*((::TESForm_Ex **)(new ((void *)(pIter)) ::Vec3()))))->FUN_004077c0())
        {
            delete *((::TESForm_Ex **)(new ((void *)(pIter)) ::Vec3()));
        }
    }
    reinterpret_cast<::FileMatchList *>((this_ptr + 0x1d0))->RemoveAll();
    *reinterpret_cast<void**>(this_ptr + 0x1d8) = this_ptr + 0x1d0;
}

struct FUN_0078ada0_shell : public TESLoadScreen
{
    bool IsRefFlag400Set();
};
// @fnv 0x0078ac60
void LoadingMenu::CollectLoadScreens(BSSimpleArray<TESLoadScreen*, 1024>& aLoadScreens)
{
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((reinterpret_cast<BSSimpleArray<unsigned short, 1024>*>(&aLoadScreens)))->Clear(false);
    for (BSSimpleList<BGSPerkEntry*>* entry =
             reinterpret_cast<BSSimpleList<BGSPerkEntry*>*>(((::BSSimpleList< ::TESLoadScreen *> *)(reinterpret_cast<::FUN_00461070_shell *>(((*reinterpret_cast<::TESDataHandler * *>(&::g_dataHandler))))->GetSomethingAtOffset128())));
         entry && ((::BGSPerkEntry *)(new ((void *)(entry)) ::Vec3())); entry = ((::BSSimpleList< ::BGSPerkEntry *> *)(reinterpret_cast<::Callees *>((entry))->FUN_00726070())))
    {
        if ((GetFloat(5) && reinterpret_cast<::FUN_0078ada0_shell *>((reinterpret_cast<TESLoadScreen*>(((::BGSPerkEntry *)(new ((void *)(entry)) ::Vec3())))))->IsRefFlag400Set()) ||
            (!GetFloat(5) &&
             ((extraCandidates && reinterpret_cast<TESLoadScreen*>(((::BGSPerkEntry *)(new ((void *)(entry)) ::Vec3())))
                                      ->MatchesFormLocation(reinterpret_cast<TESForm*>(extraCandidates))) ||
              (!extraCandidates && reinterpret_cast<::FUN_005a7110_shell *>((reinterpret_cast<TESLoadScreen*>(((::BGSPerkEntry *)(new ((void *)(entry)) ::Vec3())))))->FUN_005a7110()))))
        {
            unsigned int index = reinterpret_cast<::FUN_00438690 *>((reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(&aLoadScreens)))->FUN_007cb2e0((unsigned int *)&(reinterpret_cast<NavMeshInfo*&>(((::BGSPerkEntry *)(new ((void *)(entry)) ::Vec3())))));
            int type = reinterpret_cast<::FUN_005a7130_shell *>((reinterpret_cast<TESLoadScreen*>(((::BGSPerkEntry *)(new ((void *)(entry)) ::Vec3())))))->FUN_005a7130();
            if ((DAT_011d8907 || (unsigned char)reinterpret_cast<::FUN_00678ce0_shell *>((reinterpret_cast<DurationData*>(g_osGlobals)))->FUN_00678ce0()) &&
                type != 3 && type != 0)
                reinterpret_cast<::fnv_009a4320::FUN_009a4320_arr *>(&(aLoadScreens))->FUN_009a4320(index, 1);
        }
    }
}

class TESObjectREFR
{
  public:
};

// @fnv 0x0078ada0
bool FUN_0078ada0_shell::IsRefFlag400Set()
{
    return (((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>((((TESObjectREFR*)this)))->GetName())) & 0x400) != 0;
}

struct FUN_0078afa0_shell : public LoadingMenu
{
    void FUN_0078afa0(bool);
};

// @fnv 0x0078afa0
void FUN_0078afa0_shell::FUN_0078afa0(bool abShow)
{
    SetFloatFlag(6, abShow);
}

struct StrH
{
    operator const char*() const;
};
struct ListH
{
};
struct LM0078b650
{
    char pad[0xd0];
    char lst;
    void FUN_0078b650(bool b);
};
// Iterates the tile list from lst and calls Set(0xfa3, b) on each tile.
// @fnv 0x0078b650
void LM0078b650::FUN_0078b650(bool b)
{
    void* pos = (void*)(const char*)*reinterpret_cast<StrH*>(&lst);
    while (pos)
    {
        ((::Tile *)(reinterpret_cast<::ListStandIn *>((reinterpret_cast<ListH*>(&lst)))->FUN_0057cbe0((int **)&(pos))))->Set(0xfa3, b);
    }
}

namespace fnv_0078b6a0 {
struct StrH
{
    operator const char*() const;
};
struct ListH
{
};
struct LM0078b6a0
{
    char pad[0xdc];
    char lst;
    void FUN_0078b6a0(bool b);
};
// Iterates the tile list starting at lst and calls Set(0xfa3, b) on each tile.
// @fnv 0x0078b6a0
void LM0078b6a0::FUN_0078b6a0(bool b)
{
    void* pos = (void*)(const char*)*reinterpret_cast<StrH*>(&lst);
    while (pos)
    {
        ((::Tile *)(reinterpret_cast<::ListStandIn *>((reinterpret_cast<ListH*>(&lst)))->FUN_0057cbe0((int **)&(pos))))->Set(0xfa3, b);
    }
}
}  // namespace fnv_0078b6a0

struct TL
{
};
struct S78b
{
    char p0[0xb8];
    Tile* t1;
    Tile* t2;
    char p1[0xf4 - 0xc0];
    TL l1;
    char p2[0x100 - 0xf5];
    TL l2;
    void FUN_0078b6f0(bool b);
};
// Sets property 0xfa3 to b on every tile in both lists l1 and l2 and on t1 and t2.
// @fnv 0x0078b6f0
void S78b::FUN_0078b6f0(bool b)
{
    void* pos = ((void *)(::FUN_00559450((int *)&(l1))));
    while (pos)
    {
        Tile* pTile = ((::Tile *)(reinterpret_cast<::ListStandIn *>(&(l1))->FUN_0057cbe0((int **)&(pos))));
        if (pTile)
            pTile->Set(0xfa3, b);
    }
    pos = ((void *)(::FUN_00559450((int *)&(l2))));
    while (pos)
    {
        Tile* pTile = ((::Tile *)(reinterpret_cast<::ListStandIn *>(&(l2))->FUN_0057cbe0((int **)&(pos))));
        if (pTile)
            pTile->Set(0xfa3, b);
    }
    t1->Set(0xfa3, b);
    t2->Set(0xfa3, b);
}

namespace fnv_0078b7c0 {
struct StrH
{
    operator const char*() const;
};
struct ListH
{
};
struct LM0078b7c0
{
    char pad[0xe8];
    char lst;
    void FUN_0078b7c0(bool b);
};
// Iterates the tile list starting at lst and calls Set(0xfa3, b) on each tile.
// @fnv 0x0078b7c0
void LM0078b7c0::FUN_0078b7c0(bool b)
{
    void* pos = (void*)(const char*)*reinterpret_cast<StrH*>(&lst);
    while (pos)
    {
        ((::Tile *)(reinterpret_cast<::ListStandIn *>((reinterpret_cast<ListH*>(&lst)))->FUN_0057cbe0((int **)&(pos))))->Set(0xfa3, b);
    }
}
}  // namespace fnv_0078b7c0

struct LoadScreenTypeData
{
    int DataType;
    char m_acFirstString[40];
    char m_acSecondString[40];
    unsigned int m_uiTrailingValue;
};
struct FUN_0078b9b0_shell : public LoadingMenu
{
    void FUN_0078b9b0(void*);
};

class BGSLoadGameBuffer;

class TESObjectREFR;
class Interface
{
  public:
public:
    static void SetLookAtReference(::TESObjectREFR *);
public:
    static float GetThirdInterfaceFloat();
public:
    static float GetFourthInterfaceFloat();
};

class Tile;
class InterfaceManager
{
  public:
    static float __cdecl UpdateInterfaceState(void);
public:
    ::Tile *FUN_00586150();
};


extern const double DAT_0106e7f8;

// @fnv 0x0078b9b0
void FUN_0078b9b0_shell::FUN_0078b9b0(void* apData)
{
    if (apData == 0)
    {
        ::FUN_0040fbe0(
            );
        return;
    }

    float fSafeWidth;
    float fConvertedYPos;
    float fSafeHeight;
    float fConvertedHeight;
    float fCurrentScreenWidth = InterfaceManager::UpdateInterfaceState();
    float fCurrentScreenHeight = FUN_00715da0();
    fSafeWidth = fCurrentScreenWidth - FUN_007177c0();
    fSafeHeight = fCurrentScreenHeight - ::fnv_00717820::FUN_00717820();

    float fConvertedWidth;
    float fConvertedXPos = (double)((unsigned int*)apData)[1] / 1280.0 * fCurrentScreenWidth;
    fConvertedYPos = (double)((unsigned int*)apData)[2] / DAT_0106e7f8 * fCurrentScreenHeight;
    fConvertedWidth = (double)((unsigned int*)apData)[3] / 1280.0 * fCurrentScreenWidth;
    fConvertedHeight = (double)((unsigned int*)apData)[4] / 1280.0 * fCurrentScreenHeight;

    if (((unsigned int*)apData)[0] != 0)
    {
        this->unkc0 = (int)FUN_00404010(fConvertedXPos, FUN_007177c0());
        this->unkc4 = (int)FUN_00404010(fConvertedYPos, ::fnv_00717820::FUN_00717820());
        this->unkc8 =
            (int)FUN_0040ebd0((float)this->unkc0 + fConvertedWidth, fSafeWidth);
        this->unkcc =
            (int)FUN_0040ebd0((float)this->unkc4 + fConvertedHeight, fSafeHeight);
    }
}

struct LMStandIn
{
    char pad[0x1dc];
    int v;
    void FUN_0078bb60(int);
    void FUN_0078bb40();
};
// @fnv 0x0078bb40
void LMStandIn::FUN_0078bb40()
{
    FUN_0078bb60(v);
}

// @fnv 0x0078bc60
int FUN_0078bc60(int apObject)
{
    return *(int*)(apObject + 0x34) + 0x18;
}

struct RecursiveLock
{
    void Enter(char*);
    void Lock(char*);
    void Unlock();
    bool TryLock();
    void Wait();
    static void OutputTrackingInfo();
    unsigned int QOwningThreadID();
    unsigned int QCurrentLockCount();
    void InitWithSpinCount(unsigned long);
    void* __vecDelDtor(unsigned int);
    char CriticalSection[28];
    unsigned long m_uiFirstValue;
    unsigned long m_uiSecondValue;
    int m_uiRecursionCount;
};

class NiRenderer
{
  public:
};

class TaskThreadManager
{
  public:
    static TaskThreadManager* __cdecl GetSingleton();
};

int FUN_0078d1d0(RecursiveLock*);
bool __cdecl BSSpinLockGlobalTryLock(void);

struct MTRenderingSystem_Helper
{
};

struct InterfaceManager_Helper
{
};

struct Tile_Helper : public Tile
{
};

extern bool DAT_011c70f8;

// @fnv 0x0078d080
void __cdecl FUN_0078d080(void)
{
    ::FUN_004a0370((char *)(FUN_0043c4b0()));
    RecursiveLock* pTileCritSect = ((::RecursiveLock *)(::FUN_00713d70()));
    if (!reinterpret_cast<::s44b130::Lock *>((pTileCritSect))->FUN_0044b130())
    {
        reinterpret_cast<::fnv_004a03c0::DD *>((FUN_0043c4b0()))->FUN_004a03c0();
        return;
    }

    if (!FUN_0078d1d0(&(*reinterpret_cast<::RecursiveLock *>(&::DAT_011f4380))))
    {
        reinterpret_cast<::S_0082f1f0_Lock *>((pTileCritSect))->FUN_0082f1f0();
        reinterpret_cast<::fnv_004a03c0::DD *>((FUN_0043c4b0()))->FUN_004a03c0();
        return;
    }

    if (DAT_011a0295 && !BSSpinLockGlobalTryLock())
    {
        reinterpret_cast<::S_0082f1f0_Lock *>(&((*reinterpret_cast<::RecursiveLock *>(&::DAT_011f4380))))->FUN_0082f1f0();
        reinterpret_cast<::S_0082f1f0_Lock *>((pTileCritSect))->FUN_0082f1f0();
        reinterpret_cast<::fnv_004a03c0::DD *>((FUN_0043c4b0()))->FUN_004a03c0();
        return;
    }

    if (DAT_011a0295)
    {
        ::fnv_00a04200::FUN_00a04200(true);
        FUN_00452530();
    }

    reinterpret_cast<::ThreadCoordinator_ba2f30 *>((reinterpret_cast<MTRenderingSystem_Helper*>(TaskThreadManager::GetSingleton())))->FUN_00ba2f30();
    for (int i = 1; i < 23; ++i)
    {
        reinterpret_cast<::ThreadStageSignalDetail::RenderingStageController *>((reinterpret_cast<MTRenderingSystem_Helper*>(TaskThreadManager::GetSingleton())))->FUN_00ba30f0(0, i);
        ::RenderStageWait::FUN_00ba3130((::RenderStageWait::ThreadStages *)(reinterpret_cast<MTRenderingSystem_Helper*>(TaskThreadManager::GetSingleton())), (void *)(1), i, {});
    }

    DAT_011c70f8 = true;
    reinterpret_cast<::fnv_00713fb0::MenuMgr *>((reinterpret_cast<InterfaceManager_Helper*>(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->RenderMenu(0, 0);
    DAT_011c70f8 = false;

    reinterpret_cast<::FUN_00ba2fa0_C *>((reinterpret_cast<MTRenderingSystem_Helper*>(TaskThreadManager::GetSingleton())))->FUN_00ba2fa0();
    reinterpret_cast<::fnv_004a03c0::DD *>((FUN_0043c4b0()))->FUN_004a03c0();
    reinterpret_cast<::S_0082f1f0_Lock *>((pTileCritSect))->FUN_0082f1f0();
    reinterpret_cast<::S_0082f1f0_Lock *>(&((*reinterpret_cast<::RecursiveLock *>(&::DAT_011f4380))))->FUN_0082f1f0();
}

extern void*(* DAT_00fdf0b4)(void*, long, long, const char*);

// @fnv 0x0078d3b0
CountingSemaphore* InitSemaphore(CountingSemaphore* pThis)
{
    pThis->iCount = 0;
    pThis->m_iMaximumCount = 1;
    pThis->hSemaphore = DAT_00fdf0b4(0, 0, 1, 0);
    return pThis;
}

struct PlayerCharacter
{
};
float __cdecl GetLevelProgress();
// Stores the player's FindAudioEntry result, GetLevelProgress result and level into g_011da168, DAT_011da16c and DAT_011da170.
// @fnv 0x0078d670
void FUN_0078d670()
{
    *(int*)&g_011da168 = ((int)(reinterpret_cast<::FUN_00952b30_Class *>((::_g_thePlayer))->FindAudioEntry()));
    DAT_011da16c = GetLevelProgress();
    DAT_011da170 = reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>((::_g_thePlayer))->FUN_0087f9f0();
}

namespace fnv_0078d880 {
class NavMeshInfo;
template <> class BSSimpleArray<NavMeshInfo*, 1024>
{
  public:
    void FUN_006b3eb0(unsigned int, bool);
};

// @fnv 0x0078d880
void* FUN_0078d880(void* pThis)
{
    *reinterpret_cast<int**>(pThis) = &::DAT_0107410c;
    reinterpret_cast<BSSimpleArray<NavMeshInfo*, 1024>*>(pThis)->FUN_006b3eb0(0, false);
    return pThis;
}
}  // namespace fnv_0078d880


class GlobalObject_00869f00
{
  public:
};

// @fnv 0x0078d8b0
void FUN_0078d8b0(GlobalObject_00869f00* pThis)
{
    *(int**)pThis = &DAT_0107410c;
    reinterpret_cast<::fnv_008454f0::FUN_008454f0 *>((pThis))->Clear(true);
}

namespace p07 {
struct DtorStandIn
{
    void FUN_0083dec0();
};
struct DelStandIn
{
    void* DestroyAndFree(unsigned int flags);
};
// Runs the destructor, then frees this object if the flags bit 0 is set, and returns this.
// @fnv 0x00788770
void* DelStandIn::DestroyAndFree(unsigned int flags)
{
    ((DtorStandIn*)this)->FUN_0083dec0();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}

namespace fnv_007890e0 {
struct NiUpdateData
{
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
    char _pad_9[3];
};
struct FUN_007890e0_shell : public LoadingMenu
{
    void InitLoadingMenu(TESForm*);
};

class NiProperty;
class TESObjectREFR;

class NiFixedString
{
  public:
    NiFixedString(const char*);
    ~NiFixedString();
    const char* m_kHandle;
};

struct NiUpdateDataH
{
    void FUN_0043d410(float, bool, bool);
    float fTime;
    bool m_bUpdateEnabled;
    bool m_bRender;
    bool m_bInterpolate;
    bool m_bTimeToDie;
    bool m_bVisible;
};

class NiNodeV;

class NiAVObjectV
{
  public:
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual NiNodeV* IsSceneNode();
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual NiAVObjectV* GetObjectByName(const NiFixedString&);
};

class NiNodeV : public NiAVObjectV
{
  public:
};

class NiRendererV
{
  public:
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void SetBackgroundColor(int*);
};

struct Tile3D
{
};

struct Tile_
{
    virtual ~Tile_();
};

struct TileEx
{
};
struct TileH
{
};
struct FUN_00424940_shell
{
};
struct FUN_0041fd00_shell
{
};
struct HUDMainMenu
{
};
struct InterfaceH
{
};
struct BGSMoviePlayer
{
};
struct TESGlobalValueReader
{
};
struct OSGlobalsH
{
};
struct TESObjectCELL
{
};
struct FUN_00575d10_shell
{
};
struct Setting_S
{
};
struct FUN_0078a5a0_shell
{
    void UpdateLoadingScreens();
};
struct FUN_0078a280_shell
{
    void UpdateLoadingScreenText(bool);
};
struct FUN_0078a9f0_shell
{
};
struct FUN_0078a3e0_shell
{
    void ApplyLoadingScreenTexture(bool);
};
struct FUN_0078cc50_shell
{
    void FUN_0078cc50();
};
struct BSAudio
{
    void SetAudioProperty(unsigned int, unsigned int, unsigned int);
};

extern const float DAT_01073f20;
struct PC7d;

struct LoadingMenuH
{
    void SetTileVisible(int, bool);
};
struct FUN_0078afa0_shell
{
};
struct FUN_0078a230_shell
{
};
struct NiRendererH
{
};


// @fnv 0x007890e0
void FUN_007890e0_shell::InitLoadingMenu(TESForm* apLocation)
{
    Tile_* psleep;

    this->nextTipTime = 0;
    if (reinterpret_cast<::TileListBoxCalls *>((((TileEx*)*(Tile**)&this->unk04)))->GetFloat(0xfa7) == ::DAT_010704f0 ||
        reinterpret_cast<::TileListBoxCalls *>((((TileEx*)*(Tile**)&this->unk04)))->GetFloat(0xfa7) == ::DAT_010704e8)
    {
        reinterpret_cast<::FUN_00a012d0_t *>(((*(Tile**)&this->unk04)))->FUN_00a012d0(0xfad, ::Tile::GetInterfaceScale(), true);
    }

    if (reinterpret_cast<::FUN_00424940_shell *>((((FUN_00424940_shell*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00424940() != 3)
        reinterpret_cast<::FUN_0041fd00_shell *>((((FUN_0041fd00_shell*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_0041fd00(2);

    ::fnv_00771700::FUN_00771700(5);
    ::UpdateActivatePrompt((::RefX *)(::fnv_007890e0::TESObjectREFR *)(0), false, false);
    ::Interface::SetLookAtReference((::TESObjectREFR *)(::fnv_007890e0::TESObjectREFR *)(0));

    if ((*reinterpret_cast<::fnv_007890e0::PC7d * *>(&::_g_thePlayer)) && !reinterpret_cast<::FUN_00ec17c0_Class *>(((*reinterpret_cast<::fnv_007890e0::BGSMoviePlayer * *>(&::DAT_0126fac4))))->FUN_00ec17c0())
        reinterpret_cast<::fnv_00ec25e0::FUN_00ec25e0_cls *>(((*reinterpret_cast<::fnv_007890e0::BGSMoviePlayer * *>(&::DAT_0126fac4))))->FUN_00ec25e0();

    psleep = ((::fnv_007890e0::Tile_ *)(::FUN_00a09030(0x3f4)));
    if (psleep)
        delete psleep;

    *(TESForm**)((char*)this + 0x1e8) = apLocation;

    if (DAT_011a0294 || reinterpret_cast<::FUN_00526ac0_shell *>(((*reinterpret_cast<::fnv_007890e0::TESGlobalValueReader * *>(&::DAT_011c3f3c))))->FUN_00526ac0() != ::_DAT_01012060)
    {
        ((LoadingMenuH*)this)->SetTileVisible(0, false);
    }
    else if (DAT_011d8907 || ((bool)(reinterpret_cast<::FUN_00678ce0_shell *>((((OSGlobalsH*)g_osGlobals)))->FUN_00678ce0())))
    {
        reinterpret_cast<::FUN_0078afa0_shell *>((((FUN_0078afa0_shell*)this)))->FUN_0078afa0(false);
        ::FUN_004a0370((char *)(((NiRendererH*)((::fnv_007890e0::NiRendererV *)(::FUN_0043c4b0())))));
        reinterpret_cast<::FUN_0078a230_shell *>((((FUN_0078a230_shell*)this)))->FUN_0078a230();
        reinterpret_cast<::fnv_004a03c0::DD *>((((NiRendererH*)((::fnv_007890e0::NiRendererV *)(::FUN_0043c4b0())))))->FUN_004a03c0();
    }
    else
    {
        if (*(TESForm**)((char*)this + 0x1e8) && !reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((::g_BGSSaveLoadGame))->FUN_0042ce10())
        {
            switch ((*(TESForm**)((char*)this + 0x1e8))->GetFormType())
            {
            case 0x39:
                reinterpret_cast<::LoadingMenu *>((((LoadingMenuH*)this)))->SetFloatFlag(9, reinterpret_cast<::TESObjectCELL *>((((TESObjectCELL*)*(TESForm**)((char*)this + 0x1e8))))->IsCellInterior());
                break;
            case 0x3a:
            case 0x3b:
            case 0x3c:
            case 0x3d:
            case 0x3e:
            case 0x3f:
            case 0x40:
            case 0x69:
                reinterpret_cast<::LoadingMenu *>((((LoadingMenuH*)this)))->SetFloatFlag(9, reinterpret_cast<::fnv_00575d10::FUN_00575d10_shell *>((((FUN_00575d10_shell*)*(TESForm**)((char*)this + 0x1e8))))->FUN_00575d10());
                break;
            }
        }
        if (reinterpret_cast<::LoadingMenu *>((((LoadingMenuH*)this)))->GetFloat(9))
        {
            ((LoadingMenuH*)this)->SetTileVisible(0xb, false);
            reinterpret_cast<::LoadingMenu *>((((LoadingMenuH*)this)))->SetFloatFlag(4, false);
            *(unsigned int*)((char*)this + 0x1e4) = ((unsigned int)(::FUN_00457fe0()));
            ::DAT_011a0295 = true;
        }
        else
        {
            reinterpret_cast<::FUN_0078afa0_shell *>((((FUN_0078afa0_shell*)this)))->FUN_0078afa0(true);
            reinterpret_cast<::LoadingMenu *>((((LoadingMenuH*)this)))->RefreshLoadingScreen();
        }
        ::FUN_004a0370((char *)(((NiRendererH*)((::fnv_007890e0::NiRendererV *)(::FUN_0043c4b0())))));
        reinterpret_cast<::FUN_0078a230_shell *>((((FUN_0078a230_shell*)this)))->FUN_0078a230();
        reinterpret_cast<::fnv_004a03c0::DD *>((((NiRendererH*)((::fnv_007890e0::NiRendererV *)(::FUN_0043c4b0())))))->FUN_004a03c0();
    }

    ((::fnv_007890e0::NiRendererV *)(::FUN_0043c4b0()))->SetBackgroundColor(&(*reinterpret_cast<int *>(&::DAT_011a9bd0)));

    if (((::fnv_007890e0::NiNodeV *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((((Tile3D*)(this->m_pTiles[11]))))->FUN_0056c7f0())))
    {
        reinterpret_cast<::FUN_00440490_shell *>((((::fnv_007890e0::NiNodeV *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((((Tile3D*)(this->m_pTiles[11]))))->FUN_0056c7f0()))))->FUN_00440490(reinterpret_cast<::FUN_00450410_Class *>(&((*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1218))))->FUN_00450410());
        reinterpret_cast<::FUN_00a012d0_t *>(((this->m_pTiles[11])))->FUN_00a012d0(0x1004, *((float *)&(::FUN_00403e20((float *)(((Setting_S*)&(*reinterpret_cast<::GlobalObject_0044f440 *>(&::originalRuntimeFloatSetting1218))))))), true);
        reinterpret_cast<::NiAVObject *>((((::fnv_007890e0::NiNodeV *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((((Tile3D*)(this->m_pTiles[11]))))->FUN_0056c7f0()))))->SetLocalRotation(1.5707964f, 1.0f, 0.0f, 0.0f);
    }
    else
    {
        ::FUN_005b5e40();
    }

    if (!reinterpret_cast<::LoadingMenu *>((((LoadingMenuH*)this)))->GetFloat(9))
    {
        NiUpdateDataH data;
        NiAVObjectV* pav;
        NiNodeV* pnode;
        Tile3D* p3dtile;

        pav = ((::fnv_007890e0::NiNodeV *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((((Tile3D*)(this->m_pTiles[0]))))->FUN_0056c7f0()))->GetObjectByName(NiFixedString("Slide01"));
        pnode = pav->IsSceneNode();
        if (pnode)
        {
            *(NiProperty**)((char*)this + 0x1ec) = ((::fnv_007890e0::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((((::fnv_007890e0::NiAVObjectV *)(reinterpret_cast<::S_FUN_0045bc00 *>((pnode))->FUN_0045bc00(0)))))->FUN_00a59d30(((unsigned int)(::FUN_00438220())))));
            pnode = (NiNodeV*)((::fnv_007890e0::NiNodeV *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((((Tile3D*)(this->m_pTiles[0]))))->FUN_0056c7f0()))
                        ->GetObjectByName(NiFixedString("Slide02"));
            *(NiProperty**)&this->m_pAlternateTileShaderState = ((::fnv_007890e0::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((((::fnv_007890e0::NiAVObjectV *)(reinterpret_cast<::S_FUN_0045bc00 *>((pnode))->FUN_0045bc00(0)))))->FUN_00a59d30(((unsigned int)(::FUN_00438220())))));
        }
        else
        {
            *(NiProperty**)((char*)this + 0x1ec) = ((::fnv_007890e0::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((pav))->FUN_00a59d30(((unsigned int)(::FUN_00438220())))));
            pav = ((::fnv_007890e0::NiNodeV *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((((Tile3D*)(this->m_pTiles[0]))))->FUN_0056c7f0()))->GetObjectByName(NiFixedString("Slide02"));
            *(NiProperty**)&this->m_pAlternateTileShaderState = ((::fnv_007890e0::NiProperty *)(reinterpret_cast<::FUN_00a59d30_C *>((pav))->FUN_00a59d30(((unsigned int)(::FUN_00438220())))));
        }

        ((FUN_0078a5a0_shell*)this)->UpdateLoadingScreens();
        if (!DAT_011a0294)
        {
            ((FUN_0078a280_shell*)this)->UpdateLoadingScreenText(false);
            ::FUN_0078a9f0((char *)(((FUN_0078a9f0_shell*)this)));
            ((FUN_0078a3e0_shell*)this)->ApplyLoadingScreenTexture(false);
            reinterpret_cast<::LoadingMenu *>((((LoadingMenuH*)this)))->UpdateLoadingScreenTip();
        }

        reinterpret_cast<::FUN_00440490_shell *>((((::fnv_007890e0::NiNodeV *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((((Tile3D*)(this->m_pTiles[0]))))->FUN_0056c7f0()))))->FUN_00440490(DAT_01073f20);
        reinterpret_cast<::NiAVObject *>((((::fnv_007890e0::NiNodeV *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((((Tile3D*)(this->m_pTiles[0]))))->FUN_0056c7f0()))))->SetLocalRotation(1.5707964f, 1.0f, 0.0f, 0.0f);
        reinterpret_cast<::FUN_00a012d0_t *>(((this->m_pTiles[0])))->FUN_00a012d0(0x1004, ((double)(::Interface::GetFourthInterfaceFloat())) / ((double)(::Interface::GetThirdInterfaceFloat())), true);

        p3dtile = (Tile3D*)(this->m_pTiles[0]);
        reinterpret_cast<::FUN_00a20cc0_t *>((p3dtile))->FUN_00a20cc0("Left");
        data.FUN_0043d410(0.0f, true, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((::fnv_007890e0::NiNodeV *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((p3dtile))->FUN_0056c7f0()))))->FUN_00a59c60((int)&(data));
        ((FUN_0078cc50_shell*)this)->FUN_0078cc50();
        *(unsigned int*)((char*)this + 0x1e4) = 0;
    }

    ::FUN_0078d080();

    if ((DAT_011a0294 || !apLocation) && reinterpret_cast<::PatrolActorPackageData *>((((::fnv_007890e0::BSAudio *)(::FUN_00453a70()))))->IsPatrolling() &&
        !*((const char *)(reinterpret_cast<::StartMenu *>((((SettingT_GameSettingCollection_*)&g_011ded5c)))->GetMenuTitle())))
    {
        if (!reinterpret_cast<::FUN_005bb4d0_shell *>((((::fnv_007890e0::BSAudio *)(::FUN_00453a70()))))->FUN_005bb4d0())
        {
            reinterpret_cast<::FUN_00ad7230_shell *>((((::fnv_007890e0::BSAudio *)(::FUN_00453a70()))))->FUN_00ad7230(true);
            reinterpret_cast<::LoadingMenu *>((((LoadingMenuH*)this)))->SetFloatFlag(2, true);
        }
    }
    else if (!DAT_011a0294 && reinterpret_cast<::PatrolActorPackageData *>((((::fnv_007890e0::BSAudio *)(::FUN_00453a70()))))->IsPatrolling())
    {
        if (!reinterpret_cast<::FUN_005bb4d0_shell *>((((::fnv_007890e0::BSAudio *)(::FUN_00453a70()))))->FUN_005bb4d0())
        {
            reinterpret_cast<::FUN_00ad7230_shell *>((((::fnv_007890e0::BSAudio *)(::FUN_00453a70()))))->FUN_00ad7230(true);
            reinterpret_cast<::LoadingMenu *>((((LoadingMenuH*)this)))->SetFloatFlag(2, true);
        }
        ((::fnv_007890e0::BSAudio *)(::FUN_00453a70()))->SetAudioProperty(2, 1000, 6000);
    }

    this->m_uiFirstStateValue = 0;
    reinterpret_cast<::TaskQueueInterface *>((((::fnv_007890e0::NiNodeV *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((((Tile3D*)(this->m_pTiles[0]))))->FUN_0056c7f0()))))->QueueActorDisarm(true);
}
}  // namespace fnv_007890e0

struct TileList
{
};
struct TileEx : public Tile
{
    using Tile::Set;
    void Set(int aeValue, unsigned int auiValue);
};
struct LoadingTileSettings
{
    unsigned int uiHeader[5];
    float fAlpha;
    int iVisible;
    float fRed;
    float fGreen;
    float fBlue;
    unsigned int uiJustify;
};
struct LoadingMenuTips : public LoadingMenu
{
    void ApplySettingsToTiles(LoadingTileSettings* apSettings);
};

// Applies the loading tile settings (justify, alpha, visibility, colour) to every tile in two tile lists, computing X/Y positions from this menu's bounds.
// @fnv 0x0078c770
void LoadingMenuTips::ApplySettingsToTiles(LoadingTileSettings* apSettings)
{
    void* pos = ((void *)(::FUN_00559450((int *)(((TileList*)m_kFourthTileList)))));
    while (pos)
    {
        TileEx* pTile = (TileEx*)((::Tile *)(reinterpret_cast<::ListStandIn *>((((TileList*)m_kFourthTileList)))->FUN_0057cbe0((int **)&(pos))));
        if (pTile)
        {
            float fX = 0;
            switch (apSettings->uiJustify)
            {
            case 1:
                fX = this->unkc0;
                break;
            case 2:
                fX = this->unkc0 + (this->unkc8 - this->unkc0) / 2.0;
                break;
            case 4:
                fX = this->unkc8;
                break;
            }
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfa1, fX, true);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb1, (float)(this->unkc8 - this->unkc0), true);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfba, reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfb1), true);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfa2, (float)this->unkc4, true);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb0, this->unkcc - reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfa2), true);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfbb, reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfb0), true);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xffa, apSettings->fAlpha, true);
            pTile->Set(0xfb9, apSettings->iVisible);
            reinterpret_cast<::Tile *>((pTile))->Set(0xfb7, apSettings->uiJustify);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb2, apSettings->fRed, true);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb3, apSettings->fGreen, true);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb4, apSettings->fBlue, true);
            pTile->Set(0xff5, -1);
            reinterpret_cast<::FUN_00a07530_shell *>((pTile))->FUN_00a07530(8);
        }
    }
    pos = ((void *)(::FUN_00559450((int *)(((TileList*)m_kFifthTileList)))));
    while (pos)
    {
        TileEx* pTile = (TileEx*)((::Tile *)(reinterpret_cast<::ListStandIn *>((((TileList*)m_kFifthTileList)))->FUN_0057cbe0((int **)&(pos))));
        if (pTile)
        {
            float fX = 0;
            switch (apSettings->uiJustify)
            {
            case 1:
                fX = this->unkc0;
                break;
            case 2:
                fX = this->unkc0 + (this->unkc8 - this->unkc0) / 2.0;
                break;
            case 4:
                fX = this->unkc8;
                break;
            }
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfa1, fX, true);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb1, (float)(this->unkc8 - this->unkc0), true);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfba, reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfb1), true);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfa2, (float)this->unkc4, true);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb0, this->unkcc - reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfa2), true);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfbb, reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfb0), true);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xffa, apSettings->fAlpha, true);
            pTile->Set(0xfb9, apSettings->iVisible);
            reinterpret_cast<::Tile *>((pTile))->Set(0xfb7, apSettings->uiJustify);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb2, apSettings->fRed, true);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb3, apSettings->fGreen, true);
            reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb4, apSettings->fBlue, true);
            pTile->Set(0xff5, -1);
            reinterpret_cast<::FUN_00a07530_shell *>((pTile))->FUN_00a07530(8);
        }
    }
}

extern unsigned char DAT_011dcfb2;

// @fnv 0x00788a90
void FUN_00788a90(unsigned char value)
{
    DAT_011dcfb2 = value;
}

extern unsigned char DAT_011dcfb2;

// @fnv 0x00788aa0
unsigned char FUN_00788aa0()
{
    return DAT_011dcfb2;
}

// @fnv 0x00788f20
int FUN_00788f20()
{
    return 0x3ef;
}

struct NiControllerManager;
struct NiControllerSequence;
struct FUN_00789820_shell : public LoadingMenu
{
    void FUN_00789820();
};
// @fnv 0x0078d490
unsigned int LoadingMenuThread::ThreadProc()
{
    unsigned int interval = ((unsigned int)(::FUN_00457fe0()));
    unsigned int next = 50;
    while (m_bThirdThreadFlag != true)
    {
        if (((unsigned int)(::FUN_00457fe0())) < interval)
            FUN_0040fca0(interval - ((unsigned int)(::FUN_00457fe0())));
        if (m_bFirstThreadFlag &&
            (!DAT_011a0294 || *((const char *)(reinterpret_cast<::StartMenu *>((reinterpret_cast<SettingT_GameSettingCollection_*>(&g_011ded5c)))->GetMenuTitle())) ||
             !::FUN_0078a1f0((::FUN_0078a1f0_this *)(reinterpret_cast<LoadingMenu*>(BSSystemUtility::s_iUpdateEnabled)->m_pTiles[0]))))
        {
            reinterpret_cast<::FUN_00442550_shell *>(&(m_kSecondSemaphore))->ReleaseAndInitScriptRunLock();
            m_bSecondThreadFlag = true;
            reinterpret_cast<::SemaphoreWaitReceiver *>(&(m_kFirstSemaphore))->FUN_004424e0();
            SetThreadPriority(-1);
            m_bSecondThreadFlag = false;
        }
        else
        {
            interval = ((unsigned int)(::FUN_00457fe0())) + next;
        }
        reinterpret_cast<::FUN_00789820_shell *>((reinterpret_cast<LoadingMenu*>(BSSystemUtility::s_iUpdateEnabled)))->FUN_00789820();
        ::FUN_0078d080();
    }
    return 0;
}

class TESForm_Ex;
class TES;
class TESSound;
class NiControllerSequence;
enum MEDIATYPE
{
    MEDIATYPE_8 = 8
};
extern bool DAT_011da0c9;
extern float DAT_011dd300;
extern float DAT_011dd338;
extern double DAT_01073fb8;
extern GlobalObject2_0045cfe0 g_011de740;
extern GlobalObject2_0045cfe0 g_011da0f0;
void FUN_005330e0(float&, float, float);
class TESGlobalValueReader
{
  public:
};
class BGSMoviePlayer
{
  public:
};
class BSAudio
{
  public:
    void Update(bool);
};
enum MEDIATYPE;
struct FalloutAudioMedia
{
public:
    static void FadeOutMedia(int, ::MEDIATYPE);
};
class NiUpdateData
{
  public:
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    bool bUpdateGeomorphs;
    bool bUpdateShadowSceneNode;
    void* pkUpdateTask;
    NiUpdateData(float, bool, bool);
};
struct NN_00605d70
{
};
struct NiAVObjectS
{
};
struct TGF
{
};
struct TileQ
{
};
struct TV
{
};
struct NiControllerManager
{
    bool StopSequence(NiControllerSequence*, float);
};
struct EP_008c48d0
{
};
struct TESTopicInfo
{
};
struct BSSimpleListTESRaceSize
{
    int GetSize();
};
class Tile3D : public Tile
{
  public:
};
struct LoadingMenuS
{
    void FUN_0078cc50();
};

extern unsigned char DAT_011cabb8;

// @fnv 0x0078a930
unsigned char __cdecl FUN_0078a930()
{
    return DAT_011cabb8;
}

namespace fnv_0078b100 {
struct Flt
{
    operator unsigned int() const;
};
struct TL
{
};
struct TileEx
{
};
struct LoadingMenuStandIn
{
    void FUN_0078b100(float afTime, int aiState);
    void SetTileAlpha(Tile* apTile, float afTime);
};
// When aiState is 1, walks the tile list at this+0xd0, sets flag 0xfa3 to 1 on tiles where it is 0, and calls SetTileAlpha on each tile with afTime.
// @fnv 0x0078b100
void LoadingMenuStandIn::FUN_0078b100(float afTime, int aiState)
{
    if (aiState == 1)
    {
        void* pos = (void*)(unsigned int)*(Flt*)((char*)this + 0xd0);
        while (pos)
        {
            Tile* pTile = ((::Tile *)(reinterpret_cast<::ListStandIn *>((((TL*)((char*)this + 0xd0))))->FUN_0057cbe0((int **)&(pos))));
            if (pTile)
            {
                if (reinterpret_cast<::TileListBoxCalls *>((((TileEx*)pTile)))->GetFloat(0xfa3) == 0.0)
                    pTile->Set(0xfa3, 1);
                SetTileAlpha(pTile, afTime);
            }
        }
    }
}
}  // namespace fnv_0078b100

namespace fnv_0078b190 {
struct Flt
{
    operator unsigned int() const;
};
struct TL
{
};
struct TileEx
{
};
struct LoadingMenuStandIn
{
    void UpdateTiles(float afTime, int aiState);
    void SetTileAlpha(Tile* apTile, float afTime);
};
// When aiState is 1, walks the tile list at this+0xdc, sets tile flag 0xfa3 to 1 if it is 0, and calls SetTileAlpha on each tile with afTime.
// @fnv 0x0078b190
void LoadingMenuStandIn::UpdateTiles(float afTime, int aiState)
{
    if (aiState == 1)
    {
        void* pos = (void*)(unsigned int)*(Flt*)((char*)this + 0xdc);
        while (pos)
        {
            Tile* pTile = ((::Tile *)(reinterpret_cast<::ListStandIn *>((((TL*)((char*)this + 0xdc))))->FUN_0057cbe0((int **)&(pos))));
            if (pTile)
            {
                if (reinterpret_cast<::TileListBoxCalls *>((((TileEx*)pTile)))->GetFloat(0xfa3) == 0.0)
                    pTile->Set(0xfa3, 1);
                SetTileAlpha(pTile, afTime);
            }
        }
    }
}
}  // namespace fnv_0078b190

namespace fnv_0078b220 {
struct FUN_0078b220_shell : public LoadingMenu
{
    void FadeSlideTiles(float, int);
};

struct Flt
{
    operator unsigned int() const;
};
struct TL
{
};
struct TileEx
{
};
struct LoadingMenuStandIn
{
    void SetTileAlpha(Tile* apTile, float afAlpha);
};
// For slide 1 or 2, iterates the slide's tile list, marks each tile's 0xfa3 float as 1 if zero, and applies afAlpha to it and the slide's extra tile.
// @fnv 0x0078b220
void FUN_0078b220_shell::FadeSlideTiles(float afAlpha, int anSlide)
{
    void* piter;
    if (anSlide == 1)
    {
        piter = (void*)(unsigned int)*(Flt*)m_kFourthTileList;
        while (piter)
        {
            Tile* pTile = ((::Tile *)(reinterpret_cast<::ListStandIn *>((((TL*)m_kFourthTileList)))->FUN_0057cbe0((int **)&(piter))));
            if (pTile)
            {
                if (reinterpret_cast<::TileListBoxCalls *>((((TileEx*)pTile)))->GetFloat(0xfa3) == 0.0)
                    pTile->Set(0xfa3, 1);
                ((LoadingMenuStandIn*)this)->SetTileAlpha(pTile, afAlpha);
            }
        }
        ((LoadingMenuStandIn*)this)->SetTileAlpha(m_pTiles[36], afAlpha);
    }
    if (anSlide == 2)
    {
        piter = (void*)(unsigned int)*(Flt*)m_kFifthTileList;
        while (piter)
        {
            Tile* pTile = ((::Tile *)(reinterpret_cast<::ListStandIn *>((((TL*)m_kFifthTileList)))->FUN_0057cbe0((int **)&(piter))));
            if (pTile)
            {
                if (reinterpret_cast<::TileListBoxCalls *>((((TileEx*)pTile)))->GetFloat(0xfa3) == 0.0)
                    pTile->Set(0xfa3, 1);
                ((LoadingMenuStandIn*)this)->SetTileAlpha(pTile, afAlpha);
            }
        }
        ((LoadingMenuStandIn*)this)->SetTileAlpha(m_pTiles[37], afAlpha);
    }
}
}  // namespace fnv_0078b220

namespace fnv_0078b360 {
struct Flt
{
    operator unsigned int() const;
};
struct TL
{
};
struct TileEx
{
};
struct LoadingMenuStandIn
{
    void UpdateLoadingTiles(float afTime, int aiState);
    void SetTileAlpha(Tile* apTile, float afTime);
};
// When aiState is 1, walks the tile list at this+0xe8, sets flag 0xfa3 to 1 on tiles where it is 0, and calls SetTileAlpha on each tile with afTime.
// @fnv 0x0078b360
void LoadingMenuStandIn::UpdateLoadingTiles(float afTime, int aiState)
{
    if (aiState == 1)
    {
        void* pos = (void*)(unsigned int)*(Flt*)((char*)this + 0xe8);
        while (pos)
        {
            Tile* pTile = ((::Tile *)(reinterpret_cast<::ListStandIn *>((((TL*)((char*)this + 0xe8))))->FUN_0057cbe0((int **)&(pos))));
            if (pTile)
            {
                if (reinterpret_cast<::TileListBoxCalls *>((((TileEx*)pTile)))->GetFloat(0xfa3) == 0.0)
                    pTile->Set(0xfa3, 1);
                SetTileAlpha(pTile, afTime);
            }
        }
    }
}
}  // namespace fnv_0078b360

namespace fnv_0078b810 {
struct TileEx
{
};
struct TileLayout
{
    int iX;
    int iY;
    int iHeight;
    int iWidth;
    int iZoom;
    unsigned char cJustify;
};
struct FUN_0078b810_shell : LoadingMenu
{
    void CopyTileLayout();
};
// @fnv 0x0078b810
void FUN_0078b810_shell::CopyTileLayout()
{
    for (int i = 0; i < 38; i++)
    {
        int x9 = 0;
        int y4 = 0;
        int height = 0;
        int width = 0;
        int aZoom = 1;
        unsigned char justify = 4;
        if (m_pTiles[i])
        {
            x9 = (int)reinterpret_cast<::TileListBoxCalls *>((((TileEx*)m_pTiles[i])))->GetFloat(0xfa1);
            y4 = (int)reinterpret_cast<::TileListBoxCalls *>((((TileEx*)m_pTiles[i])))->GetFloat(0xfa2);
            height = (int)reinterpret_cast<::TileListBoxCalls *>((((TileEx*)m_pTiles[i])))->GetFloat(0xfb0);
            width = (int)reinterpret_cast<::TileListBoxCalls *>((((TileEx*)m_pTiles[i])))->GetFloat(0xfb1);
            aZoom = (int)reinterpret_cast<::TileListBoxCalls *>((((TileEx*)m_pTiles[i])))->GetFloat(0xfb9);
            justify = (unsigned char)reinterpret_cast<::TileListBoxCalls *>((((TileEx*)m_pTiles[i])))->GetFloat(0xfb7);
        }
        ((TileLayout*)m_kTileLayouts)[i].iX = x9;
        ((TileLayout*)m_kTileLayouts)[i].iY = y4;
        ((TileLayout*)m_kTileLayouts)[i].iHeight = height;
        ((TileLayout*)m_kTileLayouts)[i].iWidth = width;
        ((TileLayout*)m_kTileLayouts)[i].iZoom = aZoom;
        ((TileLayout*)m_kTileLayouts)[i].cJustify = justify;
    }
}
}  // namespace fnv_0078b810

void FUN_0078d670();
extern float DAT_011da16c;
extern int DAT_011da170;
struct BGSSaveFormBuffer
{
};
// @fnv 0x0078d6b0
void SaveLoadScreenData(BGSSaveFormBuffer* apSaveGameBuffer)
{
    unsigned int iElementIndex;
    void* pquest;
    bool bLocationSpecificOnly;
    FUN_0078d670();
    pquest = *(void**)&g_011da168 ? (void*)((unsigned int)(reinterpret_cast<::MagicCaster_shell *>((*(void**)&g_011da168))->FUN_0044edb0())) : 0;
    iElementIndex = *(void**)&g_011da168 ? (unsigned int)reinterpret_cast<::Callees *>((*(void**)&g_011da168))->FUN_00726070() : 0;
    reinterpret_cast<::fnv_00865df0::FUN_00865df0_holder *>((apSaveGameBuffer))->FUN_00865df0((::fnv_00865df0::TESForm *)(pquest), 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&iElementIndex, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&DAT_011da16c, 4, 0);
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&DAT_011da170, 4, 0);
    bLocationSpecificOnly = ((bool)(::FUN_0078a930()));
    reinterpret_cast<::FUN_00865e50_shell *>((apSaveGameBuffer))->FUN_00865e50(&bLocationSpecificOnly, 1, 0);
}

struct LoadingMenu_CreateProxy
{
};
// @fnv 0x0078d280
void FUN_0078d280(bool abCreate)
{
    if (BSSystemUtility::s_iUpdateEnabled)
        LoadingMenu::UpdateLoadingScreenThread();
    else if (abCreate)
        ::CreateLoadingMenuTile(0, false, false);
    if (BSSystemUtility::s_iUpdateEnabled)
        ((LoadingMenu*&)BSSystemUtility::s_iUpdateEnabled)->SetTileVisible(LoadingMenu::Tile0, false);
}

struct S0078d3f0
{
    void FUN_0078d420();
    void* FUN_0078d3f0(unsigned int);
};
struct Fake00788ab0
{
    char _pad[0x1e8];
    int f1e8;
    void FUN_00788ab0(int);
};
// If updates are enabled, param_1 is nonzero and the update object's f1e8 is zero, calls FUN_004581c0(true) and then FUN_00788ab0(param_1) on it.
// @fnv 0x00458180
void UpdateIfEnabled(int aiValue)
{
    if (BSSystemUtility::s_iUpdateEnabled != 0 && aiValue != 0 &&
        ((Fake00788ab0*)BSSystemUtility::s_iUpdateEnabled)->f1e8 == 0)
    {
        FUN_004581c0(true);
        ((Fake00788ab0*)BSSystemUtility::s_iUpdateEnabled)->FUN_00788ab0(aiValue);
    }
}

namespace fnv_007887a0 {
class NiRenderer;

struct BSS
{
    char d[8];
    ~BSS();
};
struct GO
{
    void* p;
    ~GO();
    void operator=(void*);
};
struct Flt
{
    operator unsigned int();
};
struct ListX
{
    char d[8];
    ~ListX();
};
struct Date
{
    char d[12];
    ~Date();
};
struct GlobalObject_0048f200
{
    char d[12];
    ~GlobalObject_0048f200();
};
struct PatrolActorPackageData
{
};
struct S1740
{
};
struct SndX
{
};
struct QuestX
{
};
class BSAudio
{
  public:
};
enum MEDIATYPE
{
    MEDIATYPE_0 = 0
};
class FalloutAudioMedia
{
  public:
};
struct RendX
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
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void SetBackground(void*);
};
struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
    char pad[0x24];
};

struct FUN_007887a0 : Menu_007a8b10
{
    char pad0[0xa8];
    GlobalObject_0048f200 m_kFirstTileList;
    GlobalObject_0048f200 m_kSecondTileList;
    GlobalObject_0048f200 m_kThirdTileList;
    GlobalObject_0048f200 m_kFourthTileList;
    GlobalObject_0048f200 m_kFifthTileList;
    char m_aeMiscStatIdentifiers[0xac];
    BSS m_kLoadingScreenTip;
    char m_kLoadingScreenColor[16];
    ListX m_kLoadScreenItems;
    char pad1[0x10];
    void* pLocation;
    char pad2[8];
    Date m_kFirstDate;
    Date m_kSecondDate;
    GO m_kLoadScreenTextures[4];
    char pad3[0x5c0 - 0x21c];
    virtual ~FUN_007887a0();
};

// @fnv 0x007887a0
FUN_007887a0::~FUN_007887a0()
{
    LoadingMenu::UpdateLoadingScreenThread();
    for (int i = 0; i < 4; i++)
    {
        if (*(Flt*)&m_kLoadScreenTextures[i])
        {
            ::FUN_00a61f30((const void*)(unsigned int)*(Flt*)&m_kLoadScreenTextures[i]);
            m_kLoadScreenTextures[i] = 0;
        }
    }
    DAT_011d8907 = false;
    ((RendX*)((::fnv_007887a0::NiRenderer *)(::FUN_0043c4b0())))->SetBackground(m_kLoadingScreenColor);
    if (FUN_0070edf0() || (DAT_011a0294 && *((const char *)(reinterpret_cast<::StartMenu *>((((SettingT_GameSettingCollection_*)&g_011ded5c)))->GetMenuTitle()))))
    {
        if (reinterpret_cast<::PatrolActorPackageData *>((((PatrolActorPackageData*)((::fnv_007887a0::BSAudio *)(::FUN_00453a70())))))->IsPatrolling())
            ::FalloutAudioMedia::FadeOutMedia(4000, (*(::MEDIATYPE *)&(const ::fnv_007887a0::MEDIATYPE &)((MEDIATYPE)0)));
    }
    if (::FUN_00788aa0())
    {
        ::FUN_00788a90(0);
        ::FUN_00761460(0);
        ::FalloutAudioMedia::FadeOutMedia(4000, (*(::MEDIATYPE *)&(const ::fnv_007887a0::MEDIATYPE &)((MEDIATYPE)0)));
    }
    if (((LoadingMenu*)this)->GetFloat(2) && reinterpret_cast<::FUN_005bb4d0_shell *>((((::fnv_007887a0::BSAudio *)(::FUN_00453a70()))))->FUN_005bb4d0())
        reinterpret_cast<::FUN_00ad7230_shell *>((((::fnv_007887a0::BSAudio *)(::FUN_00453a70()))))->FUN_00ad7230(false);
    reinterpret_cast<::S1740 *>((((S1740*)((::fnv_007887a0::BSAudio *)(::FUN_00453a70())))))->FUN_005d1740(1000);
    DAT_011a0294 = false;
    ::FUN_0078a940((char*)this);
    reinterpret_cast<::fnv_00ad88f0::FUN_00ad88f0_h *>((((SndX*)&m_kSecondDate)))->FUN_00ad88f0();
    reinterpret_cast<::SoundPlaybackHandle *>((((SndX*)&m_kSecondDate)))->Release();
    reinterpret_cast<::SoundPlaybackHandle *>((((SndX*)&m_kFirstDate)))->Release();
    pLocation = 0;
    BSSystemUtility::s_iUpdateEnabled = 0;
    if ((*reinterpret_cast<char * *>(&::_g_thePlayer)) && *(QuestX**)((*reinterpret_cast<char * *>(&::_g_thePlayer)) + 0xe4c))
    {
        reinterpret_cast<::TESQuest *>(((*(QuestX**)((*reinterpret_cast<char * *>(&::_g_thePlayer)) + 0xe4c))))->SetEnabled(true);
        *(QuestX**)((*reinterpret_cast<char * *>(&::_g_thePlayer)) + 0xe4c) = 0;
    }
}
}  // namespace fnv_007887a0

struct FUN_0078a280_shell : public LoadingMenu
{
    void UpdateLoadingScreenText(bool);
};

struct LoadScreenNode_r8a280
{
};
class BaseFormComponent
{
  public:
    virtual void InitializeComponent();
    virtual void ClearComponent();
    virtual void BaseFormRecord(BaseFormComponent* apComponent);
    virtual bool IsEqualToBase(BaseFormComponent* apComponent);
};
class TESDescription : public BaseFormComponent
{
  public:
    virtual const char* GetDescription(TESForm* apForm, unsigned int auiChunk);
};
// Hashes the current candidate's full name, then sets the description and game-setting text on menu tiles and marks DAT_011a0295 true.
// @fnv 0x0078a280
void FUN_0078a280_shell::UpdateLoadingScreenText(bool abRefreshCurrent)
{
    unsigned int iplateno = 0;
    const char* pName = ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&((*((::TESLoadScreen **)(new ((void *)(((LoadScreenNode_r8a280*)currentCandidate))) ::Vec3())))->fullName))->FUN_00408da0()));
    while (*pName)
        iplateno = (iplateno << 5) + iplateno + tolower(*pName++);
    iplateno %= 100000;
    if (m_uiSecondStateValue % 2 == 0)
    {
        m_iStateFlags |= 1;
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[34]))->FUN_00a01350(
            0xfc4,
            (char *)(((TESDescription*)((char*)*((::TESLoadScreen **)(new ((void *)(((LoadScreenNode_r8a280*)currentCandidate))) ::Vec3())) + 0x24))
                ->GetDescription(0, 0x43534544)),
            true);
    }
    else
    {
        m_iStateFlags |= 2;
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[35]))->FUN_00a01350(
            0xfc4,
            (char *)(((TESDescription*)((char*)*((::TESLoadScreen **)(new ((void *)(((LoadScreenNode_r8a280*)currentCandidate))) ::Vec3())) + 0x24))
                ->GetDescription(0, 0x43534544)),
            true);
    }
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[13]))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingT_GameSettingCollection_ *>(&::g_011d3000))))->GetMenuTitle()))), true);
    DAT_011a0295 = true;
}

enum MEM_CONTEXT
{
    MEM_CONTEXT_0D = 0xd
};
struct AutoMemContext
{
    int iPrev;
    AutoMemContext(MEM_CONTEXT aeContext, bool abFlag, const char* apFile, int aiLine);
    ~AutoMemContext();
};
class NiSourceTexture;
class NiTexture;
template <class T> class NiPointer
{
  public:
    T* m_pObject;
    NiPointer(T* apObject);
    ~NiPointer();
    operator T*() const;
    NiPointer& operator=(T* apObject);
};
struct LMString
{
    char* pString;
    unsigned short usLen;
    unsigned short usMaxLen;
    operator const char*() const;
};
struct LMFullName
{
};
struct LMLoadScreen
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    LMFullName fullName;
};
struct LMNode
{
};
class TES
{
  public:
};
struct NiTexture;
struct TileShaderProperty
{
public:
    void FUN_00bb7a10(::NiTexture *);
};
class LMTile
{
  public:
    virtual void vfn00();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1c();
    virtual TileShaderProperty* GetShaderProperty();
};
struct LoadingMenuX
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
    LMTile* pTileA8;
    LMTile* pTileAC;
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
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    LMString m_kLoadingScreenTip;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    LMNode* currentCandidate;
    int unk1dc;
    int unk1e0;
    int unk1e4;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    NiPointer<NiSourceTexture> m_kLoadScreenTextures[4];
    unsigned int m_uiLoadingScreenNumber;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    unsigned int m_uiSecondStateValue;
    void ApplyLoadingScreenTexture(TileShaderProperty* apProperty);
};
// @fnv 0x00789820
void FUN_00789820_shell::FUN_00789820()
{

    DAT_011a0295 = true;
    if (((LoadingMenu*)this)->m_iStateFlags & 1)
    {
        ((LoadingMenu*)this)->m_iStateFlags &= ~1;
        reinterpret_cast<::FUN_00a012d0_t *>((((LoadingMenu*)this)
            ->m_pTiles[36]))->FUN_00a012d0(0xfa2, reinterpret_cast<::TileListBoxCalls *>((((TGF*)((LoadingMenu*)this)->m_pTiles[34])))->GetFloat(0xfa2) - runtimeInitializationDouble5,
                  true);
        reinterpret_cast<::FUN_00a012d0_t *>((((LoadingMenu*)this)
            ->m_pTiles[36]))->FUN_00a012d0(0xfb0, reinterpret_cast<::TileListBoxCalls *>((((TGF*)((LoadingMenu*)this)->m_pTiles[34])))->GetFloat(0xfb0) + DAT_0101db88, true);
    }
    if (((LoadingMenu*)this)->m_iStateFlags & 2)
    {
        ((LoadingMenu*)this)->m_iStateFlags &= ~2;
        reinterpret_cast<::FUN_00a012d0_t *>((((LoadingMenu*)this)
            ->m_pTiles[37]))->FUN_00a012d0(0xfa2, reinterpret_cast<::TileListBoxCalls *>((((TGF*)((LoadingMenu*)this)->m_pTiles[35])))->GetFloat(0xfa2) - runtimeInitializationDouble5,
                  true);
        reinterpret_cast<::FUN_00a012d0_t *>((((LoadingMenu*)this)
            ->m_pTiles[37]))->FUN_00a012d0(0xfb0, reinterpret_cast<::TileListBoxCalls *>((((TGF*)((LoadingMenu*)this)->m_pTiles[35])))->GetFloat(0xfb0) + DAT_0101db88, true);
    }

    unsigned int CurrTime = ((unsigned int)(::FUN_00457fe0()));
    if (!((LoadingMenu*)this)->GetFloat(4))
    {
        unsigned int CrossTime = CurrTime - ((LoadingMenu*)this)->m_uiFirstStateValue;
        float fTileAlpha = CrossTime * DAT_01073fb8;
        if (!((LoadingMenu*)this)->m_uiFirstStateValue)
            fTileAlpha = 1.0f;
        FUN_005330e0(fTileAlpha, 0.0f, 1.0f);
        if (((LoadingMenu*)this)->m_uiSecondStateValue % 2 == 0)
            fTileAlpha = 1.0f - fTileAlpha;
        float fSlide01Alpha = fTileAlpha;
        FUN_005330e0(fSlide01Alpha, 0.0f, 1.0f);
        if (((LoadingMenu*)this)->m_pTiles[32])
            ((LoadingMenu*)this)->m_pTiles[32]->Set(0xfa9, (int)(fSlide01Alpha * 255.0));
        float fSlide02Alpha = 1.0f - fTileAlpha;
        FUN_005330e0(fSlide02Alpha, 0.0f, 1.0f);
        if (((LoadingMenu*)this)->m_pTiles[33])
            ((LoadingMenu*)this)->m_pTiles[33]->Set(0xfa9, (int)(fSlide02Alpha * 255.0));
        ((LoadingMenu*)this)->UpdateLoadScreen(*(TESLoadScreen**)((LoadingMenu*)this)->_padToTime, fSlide01Alpha, 1);
        ((LoadingMenu*)this)
            ->UpdateLoadScreen((TESLoadScreen*)*((::TESForm_Ex **)(new ((void *)(((LoadingMenu*)this)->currentCandidate)) ::Vec3())), fSlide02Alpha,
                               2);
        DAT_011a0295 = true;
    }

    if (CurrTime - ((LoadingMenu*)this)->m_uiFirstStateValue < 3000)
    {
        if (DAT_011a0294 && !((LoadingMenu*)this)->GetFloat(0) && !reinterpret_cast<::FUN_00ec17c0_Class *>((DAT_0126fac4))->FUN_00ec17c0() &&
            ::FUN_0044a670(((const char *)(reinterpret_cast<::StartMenu *>((((SettingT_GameSettingCollection_*)&g_011de740)))->GetMenuTitle()))) && !DAT_011da0c9)
        {
            char cfilename[64];
            ::FUN_00403d30(cfilename, 0, 64);
            ::FUN_00406d00(cfilename, 64, "Data\\Music\\Special\\%s.mp3",
                      ((const char *)(reinterpret_cast<::StartMenu *>((((SettingT_GameSettingCollection_*)&g_011da0f0)))->GetMenuTitle())));
            ::FUN_00761460(true);
            ::fnv_008300c0::PlayAudioMedia((*(int *)&(const ::MEDIATYPE &)(MEDIATYPE_8)), cfilename, 0, true, true, 0.0f, 0);
            FUN_00830660();
            DAT_011dd300 = 0.6f;
            DAT_011dd338 = 0.6f;
            reinterpret_cast<::TaskQueueInterface *>((((NiAVObjectS*)((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((((RgbaColor*)((LoadingMenu*)this)->m_pTiles[0])))->FUN_0056c7f0())))))->QueueActorDisarm(true);
            reinterpret_cast<::FUN_00a012d0_t *>((((LoadingMenu*)this)->m_pTiles[32]))->FUN_00a012d0(0xfa9, 0.0f, true);
            reinterpret_cast<::FUN_00a012d0_t *>((((LoadingMenu*)this)->m_pTiles[33]))->FUN_00a012d0(0xfa9, 255.0f, true);
            reinterpret_cast<::BEC16D0MoviePlayerThread *>((DAT_0126fac4))->FUN_00ec16d0((void *)(((const char *)(reinterpret_cast<::StartMenu *>((((SettingT_GameSettingCollection_*)&g_011de740)))->GetMenuTitle()))), 0, -1, 0, 0, 0.0f);
            DAT_011da0c9 = true;
            ((LoadingMenu*)this)->m_pTiles[11]->Set(0xfa3, 1);
            DAT_011a0295 = true;
        }
        else if (DAT_011a0294 && !((LoadingMenu*)this)->GetFloat(0) && !reinterpret_cast<::FUN_00ec17c0_Class *>((DAT_0126fac4))->FUN_00ec17c0() && !DAT_011da0c9 &&
                 !::FUN_0044a670(((const char *)(reinterpret_cast<::StartMenu *>((((SettingT_GameSettingCollection_*)&g_011de740)))->GetMenuTitle()))))
        {
            char cfilename[64];
            ::FUN_00403d30(cfilename, 0, 64);
            ::FUN_00406d00(cfilename, 64, "Data\\Music\\Special\\%s.mp3",
                      ((const char *)(reinterpret_cast<::StartMenu *>((((SettingT_GameSettingCollection_*)&g_011da0f0)))->GetMenuTitle())));
            ::FUN_00761460(true);
            ::fnv_008300c0::PlayAudioMedia((*(int *)&(const ::MEDIATYPE &)(MEDIATYPE_8)), cfilename, 0, true, true, 0.0f, 0);
            FUN_00830660();
            DAT_011dd300 = 0.6f;
            DAT_011dd338 = 0.6f;
            DAT_011da0c9 = true;
        }
    }
    else if (!((LoadingMenu*)this)->nextTipTime)
    {
        if (DAT_011a0294)
        {
            while (!(*reinterpret_cast<::TES * *>(&::g_TES)))
                FUN_0040fca0(5);
            reinterpret_cast<::LoadingMenuX *>((((LoadingMenuS*)this)))->ApplyLoadingScreenTexture((::TileShaderProperty *)(*(void**)((LoadingMenu*)this)->_padToUsFlags_pad1ec));
        }
        if (!*(unsigned int*)((LoadingMenu*)this)->_padToExtra && ((LoadingMenu*)this)->GetFloat(4))
            ((LoadingMenuS*)this)->FUN_0078cc50();
        else
            *(unsigned int*)((LoadingMenu*)this)->_padToExtra = ((unsigned int)(::FUN_00457fe0()));
        ((LoadingMenu*)this)->nextTipTime = *(unsigned int*)((LoadingMenu*)this)->_padToExtra;
    }
    else if (((LoadingMenu*)this)->GetFloat(4))
    {
        ((LoadingMenuS*)this)->FUN_0078cc50();
    }
    else if (!((LoadingMenu*)this)->GetFloat(9) && ((unsigned int)(::FUN_00457fe0())) >= ((LoadingMenu*)this)->nextTipTime)
    {
        Tile3D* p3dtile = (Tile3D*)((LoadingMenu*)this)->m_pTiles[0];
        if (::FUN_0078a1f0((::FUN_0078a1f0_this *)(p3dtile)))
        {
            if (!DAT_011a0294 && reinterpret_cast<::FUN_00526ac0_shell *>(((*reinterpret_cast<::TESGlobalValueReader * *>(&::DAT_011c3f3c))))->FUN_00526ac0() == ::_DAT_01012060 && !FUN_0070edf0() &&
                (!((LoadingMenu*)this)->GetFloat(3) ||
                 reinterpret_cast<::FUN_00a01230_shell *>((((TileQ*)((LoadingMenu*)this)->m_pTiles[34])))->IsTraitNonZero(0xfa3)))
                reinterpret_cast<::FUN_0078a280_shell *>((((LoadingMenuS*)this)))->UpdateLoadingScreenText(0);
            FUN_0078a9f0((char*)this);
            reinterpret_cast<::LoadingMenuX *>((((LoadingMenuS*)this)))->ApplyLoadingScreenTexture((::TileShaderProperty *)(void *)(0));
            ((NiControllerManager*)((::TESSound *)(::GetField38((char *)(((TESTopicInfo*)p3dtile))))))
                ->StopSequence((NiControllerSequence*)((void *)(reinterpret_cast<::Twin_00639b40 *>((((EP_008c48d0*)p3dtile)))->GetEntryPoint())), 0.0f);
            ((LoadingMenu*)this)->UpdateLoadingScreenTip();
            if (DAT_011a0294 && ((LoadingMenu*)this)->currentCandidate == &((LoadingMenu*)this)->candidates)
                ((LoadingMenu*)this)->SetFloatFlag(0, true);
        }
        else if (!DAT_011a0294 || !((LoadingMenu*)this)->GetFloat(0))
        {
            if (!((LoadingMenu*)this)->GetFloat(3) && !((LoadingMenu*)this)->GetFloat(8))
            {
                ((LoadingMenu*)this)->nextTipTime = ((unsigned int)(::FUN_00457fe0()));
                reinterpret_cast<::FUN_0078a1c0_shell *>((((LoadingMenuS*)this)))->ToggleFlagBit(1);
                if (reinterpret_cast<::FUN_00a20cc0_t *>((p3dtile))->FUN_00a20cc0(((LoadingMenu*)this)->GetFloat(1) ? "Forward" : "Backward"))
                {
                    ((LoadingMenu*)this)->m_uiFirstStateValue = ((unsigned int)(::FUN_00457fe0()));
                    ((LoadingMenu*)this)->m_uiSecondStateValue++;
                    if (((LoadingMenu*)this)->GetFloat(7))
                    {
                        ((LoadingMenu*)this)
                            ->SetFloatFlag(
                                8, ((BSSimpleListTESRaceSize*)&((LoadingMenu*)this)->candidates)->GetSize() == 1);
                        ((LoadingMenu*)this)->SetFloatFlag(7, false);
                    }
                    NiUpdateData data(0.0f, true, false);
                    reinterpret_cast<::FUN_00a59c60_cls *>((((NN_00605d70*)((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((((RgbaColor*)p3dtile)))->FUN_0056c7f0())))))->FUN_00a59c60((int)&(data));
                }
                else
                {
                    ::FUN_005b5e40();
                }
            }
        }
    }

    if (reinterpret_cast<::sa040a0::Owner *>((((TV*)((LoadingMenu*)this)->m_pTiles[11])))->IsAllChildrenFlag0())
        reinterpret_cast<::FUN_0078a230_shell *>((((LoadingMenuS*)this)))->FUN_0078a230();
    ::FUN_00453a70()->Update(true);
    ::UpdateMediaLocation();
}

// Builds a texture path from the current candidate's full name, creates the texture image, stores it in a rotating slot, and assigns it to a tile shader property.
// @fnv 0x0078a3e0
void LoadingMenuX::ApplyLoadingScreenTexture(TileShaderProperty* apProperty)
{
    AutoMemContext memContext(MEM_CONTEXT_0D, true,
                              "D:\\_Fallout3\\Platforms\\Common\\Code\\Fallout\\Interface\\Menus\\LoadingMenu.cpp",
                              0x423);
    ::FUN_00406f60((::FUN_00406f90_this *)&(m_kLoadingScreenTip), "%s\\%s", "Textures", ((const char *)(reinterpret_cast<::FUN_00408da0_Class *>(&((*((::LMLoadScreen **)(new ((void *)(currentCandidate)) ::Vec3())))->fullName))->FUN_00408da0())));
    NiPointer<NiSourceTexture> spTexture(0);
    reinterpret_cast<::TESTexLoader *>(((*reinterpret_cast<::TES * *>(&::g_TES))))->FUN_004568c0(m_kLoadingScreenTip, (::TexPtr< ::NiSourceTexture> &)(spTexture), false, false);
    NiPointer<NiSourceTexture>* pSlot = &m_kLoadScreenTextures[m_uiLoadingScreenNumber];
    m_uiLoadingScreenNumber++;
    if (m_uiLoadingScreenNumber >= 4)
    {
        m_uiLoadingScreenNumber = 0;
    }
    if (*pSlot)
    {
        FUN_00a61f30(*pSlot);
    }
    *pSlot = (NiSourceTexture*)spTexture;
    apProperty = (m_uiSecondStateValue % 2 == 0) ? pTileA8->GetShaderProperty() : pTileAC->GetShaderProperty();
    if (apProperty)
    {
        apProperty->FUN_00bb7a10((::NiTexture *)(::NiSourceTexture *)(spTexture));
    }
}

namespace fnv_0078c210 {
struct NiPoint3
{
    float x, y, z;
};

class TileX
{
  public:
    void Set(int aeValue, float afValue, bool abPropagate);
    void Set(int aeValue, unsigned int auiValue);
    void FUN_00a0b520();
};

struct TileListX
{
};

class SettingX
{
  public:
};

class FontManager
{
  public:
    NiPoint3 GetStringDimensions(const char* apText, int aiFont, float afWrapWidth, int aiStart);
};


struct LoadingTileSettingsX
{
    unsigned int uiHeader[5];
    float fAlpha;
    int m_iType;
    float fRed;
    float fGreen;
    float fBlue;
    unsigned int uiJustify;
};

class LoadingMenuX
{
  public:
    unsigned char _pad00[0x50];
    TileX* pXPBar;
    unsigned char _pad54[0x10];
    TileX* pXPText;
    TileX* pXPBox;
    unsigned char _pad6c[0xc0 - 0x6c];
    int iXPMin;
    int iXPMin2;
    int iXPCur;
    int iXPCur2;
    char m_kFirstTileList[12];
    char m_kSecondTileList[12];
    TileListX m_kThirdTileList;

    void ApplyXPBarSettings(LoadingTileSettingsX* apSettings);
};

// Iterates the tile list, setting XP bar, text and box tile values from the loading settings and XP counters, then applies alpha to the XP box.
// @fnv 0x0078c210
void LoadingMenuX::ApplyXPBarSettings(LoadingTileSettingsX* apSettings)
{
    void* pos = ((void *)(::FUN_00559450((int *)&(m_kThirdTileList))));
    while (pos)
    {
        TileX* pTile = ((::fnv_0078c210::TileX *)(reinterpret_cast<::ListStandIn *>(&(m_kThirdTileList))->FUN_0057cbe0((int **)&(pos))));
        if (pTile)
        {
            if (pTile == pXPBox)
            {
                reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfa1, (float)iXPMin, true);
                reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb1, (float)(iXPCur - reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfa1)), true);
                reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfba, reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfb1), true);
                reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfa2, (float)iXPMin2, true);
                reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb0, (float)(iXPCur2 - reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfa2)), true);
            }
            else
            {
                if (pTile == pXPText)
                {
                    float fStart = 0.0f;
                    switch (apSettings->uiJustify)
                    {
                    case 1:
                        fStart = 0.0f;
                        break;
                    case 2:
                        fStart = (iXPCur - iXPMin) / 2.0;
                        break;
                    case 4:
                        fStart = (float)(iXPCur - iXPMin);
                        break;
                    }
                    reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfa1, fStart, true);
                    reinterpret_cast<::Tile *>((pTile))->Set(0xfb7, apSettings->uiJustify);
                    reinterpret_cast<::Tile *>((pTile))->Set(0xfb9, apSettings->m_iType);
                    reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb1, (float)(iXPCur - iXPMin), true);
                    reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfba, reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfb1), true);
                    NiPoint3 kBounds = ((::fnv_0078c210::FontManager *)(::FontManager::Instance()))->GetStringDimensions(
                        ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::fnv_0078c210::SettingX *>(&::g_011d2358))))->GetMenuTitle())), apSettings->m_iType, reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfba), 0);
                    float m_fGlyphExtent = kBounds.y;
                    reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb0, m_fGlyphExtent, true);
                }
                else if (pTile == pXPBar)
                {
                    char buffer[260];
                    ::FUN_00406d00(buffer, 0x104, "%i", (unsigned int)reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0x1005));
                    float fNum = ((::fnv_0078c210::FontManager *)(::FontManager::Instance()))
                                     ->GetStringDimensions(buffer, apSettings->m_iType, reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0xfba), 0)
                                     .x;
                    reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfa1, fNum, true);
                    char acLevel2[260];
                    ::FUN_00406d00(acLevel2, 0x104, "%i", (unsigned int)reinterpret_cast<::TileListBoxCalls *>((pTile))->GetFloat(0x1006));
                    float fRightWidth = ((::fnv_0078c210::FontManager *)(::FontManager::Instance()))
                                            ->GetStringDimensions(acLevel2, apSettings->m_iType,
                                                                  (float)(((iXPCur - iXPMin) - fNum) / 2.0), 0)
                                            .x;
                    reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb1, (float)((iXPCur - iXPMin) - fNum * 2.0f - fRightWidth), true);
                }
                reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb2, apSettings->fRed, true);
                reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb3, apSettings->fGreen, true);
                reinterpret_cast<::FUN_00a012d0_t *>((pTile))->FUN_00a012d0(0xfb4, apSettings->fBlue, true);
                reinterpret_cast<::Tile *>((pTile))->Set(0xff5, -1);
                reinterpret_cast<::FUN_00a07530_shell *>((pTile))->FUN_00a07530(8);
            }
        }
    }
    reinterpret_cast<::FUN_00a012d0_t *>((pXPBox))->FUN_00a012d0(0xffa, apSettings->fAlpha, true);
    pXPBox->FUN_00a0b520();
}
}  // namespace fnv_0078c210

class Base_b7116
{
  public:
    virtual ~Base_b7116();
    unsigned int unk04[11];
};

class Sub_b7116
{
  public:
    unsigned int unk00;
    unsigned int unk04;
    unsigned int unk08;
    ~Sub_b7116();
};

class FUN_0078d420 : public Base_b7116
{
  public:
    Sub_b7116 unk30;
    Sub_b7116 unk3c;

    virtual ~FUN_0078d420();
};
// Calls FUN_0078d420 on this, deallocates this when flags has bit 0 set, and returns this.
// @fnv 0x0078d3f0
void* S0078d3f0::FUN_0078d3f0(unsigned int flags)
{
    reinterpret_cast<::FUN_0078d420 *>((this))->FUN_0078d420::~FUN_0078d420();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}

// Destructor for the class; destroys the two Sub_b7116 members unk3c and unk30.
// @fnv 0x0078d420
FUN_0078d420::~FUN_0078d420()
{}

class LoadingMenuCreateMenu;
class LoadingMenuCreateTile : public Tile
{
  public:
};
class LoadingMenuCreateProvider
{
  public:
};
class LoadingMenuCreateMenu
{
  public:
    virtual ~LoadingMenuCreateMenu();
    virtual void vfn04();
    virtual void vfn08();
    virtual void vfn0c();
    virtual void vfn10();
    virtual void vfn14();
    virtual void vfn18();
    virtual void vfn1c();
    virtual void vfn20();
    virtual void vfn24();
    virtual void vfn28();
    virtual void vfn2c();
    virtual void vfn30();
    virtual int GetID();
    void FUN_00788ab0(TESForm*);
};
extern bool DAT_011da0c8;
void* __cdecl operator new(unsigned int);

// Looks up a loading-menu tile by id; if missing, loads loading_menu.xml, initialises the menu, creates the thread and returns the tile.
// @fnv 0x00788cc0
Tile* __cdecl CreateLoadingMenuTile(TESForm* form, bool refresh, bool visible)
{
    LoadingMenuCreateTile* menu = ((::LoadingMenuCreateTile *)(::FUN_00a09030(FUN_00788f20())));
    if (menu)
    {
        reinterpret_cast<::LoadingMenu *>(((*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled))))->SetFloatFlag(3, true);
        (*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled))->FUN_00788ab0(form);
        reinterpret_cast<::LoadingMenu *>(((*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled))))->SetFloatFlag(10, visible);
        return menu;
    }
    DAT_011da0c8 = true;
    LoadingMenuCreateTile* existing = ((::LoadingMenuCreateTile *)(reinterpret_cast<::fnv_00a01b00::TileLoader *>((((::LoadingMenuCreateTile *)(reinterpret_cast<::InterfaceManager *>((reinterpret_cast<LoadingMenuCreateProvider*>(((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_00586150()))))->FUN_00a01b00((void *)("Data\\Menus\\loading_menu.xml"))));
    DAT_011da0c8 = false;
    LoadingMenuCreateMenu* tile = ((::LoadingMenuCreateMenu *)(reinterpret_cast<::FUN_00a03c90_shell *>((existing))->FUN_00a03c90()));
    if (tile && tile->GetID() == FUN_00788f20())
    {
        ::LoadingMenu::SetLoadingScreenVisible(0);
        reinterpret_cast<::FUN_00a1dc70_shell *>((tile))->FUN_00a1dc70((::TileMenu *)(existing), false);
        (*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled)) = tile;
        reinterpret_cast<::fnv_0078b810::FUN_0078b810_shell *>(((*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled))))->CopyTileLayout();
        reinterpret_cast<::LM2 *>(((*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled))))->FUN_00788f30();
        ::FUN_00788f80((char *)((*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled))));
        reinterpret_cast<::fnv_00789080::LM3 *>(((*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled))))->FUN_00789080();
        reinterpret_cast<::S788 *>(((*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled))))->FUN_00788fe0();
        reinterpret_cast<::fnv_0078b6a0::LM0078b6a0 *>(((*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled))))->FUN_0078b6a0(false);
        reinterpret_cast<::S78b *>(((*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled))))->FUN_0078b6f0(false);
        reinterpret_cast<::LM0078b650 *>(((*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled))))->FUN_0078b650(false);
        reinterpret_cast<::fnv_0078b7c0::LM0078b7c0 *>(((*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled))))->FUN_0078b7c0(false);
        reinterpret_cast<::fnv_007890e0::FUN_007890e0_shell *>(((*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled))))->InitLoadingMenu(form);
        reinterpret_cast<::LoadingMenu *>(((*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled))))->SetFloatFlag(10, visible);
        if (!(*reinterpret_cast<::LoadingMenuThread * *>(&::BSSystemUtility::ms_pSystemUtility)))
            (*reinterpret_cast<::LoadingMenuThread * *>(&::BSSystemUtility::ms_pSystemUtility)) = new LoadingMenuThread;
        else if (refresh)
            ::BSSystemUtility::GetRandomGenerator();
        reinterpret_cast<LoadingMenu*>((*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled)))->m_pTiles[32]->Set(0xfa9, 0);
        reinterpret_cast<LoadingMenu*>((*reinterpret_cast<::LoadingMenuCreateMenu * *>(&::BSSystemUtility::s_iUpdateEnabled)))->m_pTiles[33]->Set(0xfa9, 0);
        return existing;
    }
    else if (tile && reinterpret_cast<::Callees *>((tile))->FUN_00726070())
    {
        delete tile;
    }
    return 0;
}

struct ScreenPath
{
    void Set(const char*);
};
struct ScreenEntry
{
    int unk00, unk04, unk08, unk0c, unk10, unk14;
    ScreenPath path;
    int unk1c, unk20, unk24, unk28, unk2c, unk30, unk34, unk38, unk3c;
    static void* operator new(unsigned int) throw();
    static void operator delete(void*);
    ScreenEntry();
};
struct ScreenList
{
    bool Empty();
    unsigned int Count();
    void Add(ScreenEntry* const&);
};
struct ScreenArray
{
    int data, size, capacity, grow;
    ScreenArray();
    ~ScreenArray();
};
struct SettingProxy
{
    int a, b, c;
};
extern SettingProxy screenNames[];
struct FUN_0078a5a0_cls : LoadingMenuX
{
    void UpdateLoadingScreens();
    void Gather(ScreenArray&);
    void Build(ScreenArray&);
};
template <class T> class NiTListItem;
template <class T> class NiTPointerList
{
  public:
    NiTListItem<T>* FUN_00726070();
    T& GetPrev(NiTListItem<T>*& position);
};
struct LoadingStatsTile : Tile
{
    int unk00;
    NiTPointerList<Tile*> children;
};
struct LoadingStatsSettings
{
    LoadingTileSettings first;
    struct Secondary
    {
        int header0;
        int header1;
        int header2;
        int header3;
        float fAlpha;
        int iVisible;
        float fRed;
        float fGreen;
        float fBlue;
        unsigned int uiJustify;
        unsigned int count;
    } second;
};
struct LoadingStatsMenu
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
    LoadingStatsTile* firstStats;
    LoadingStatsTile* secondStats;
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
    LoadingStatsTile* container;
    int unk0a8;
    int unk0ac;
    int unk0b0;
    int unk0b4;
    int unk0b8;
    int unk0bc;
    int left;
    int top;
    int right;
    int bottom;
    void ApplySettings(LoadingStatsSettings* settings);
};
struct Font
{
};
struct Extent
{
    float x;
    float y;
    float z;
};
struct FontMgr
{
    Font* fonts[8];
    void Measure(Extent*, const char*, int, float, int);
};
struct TileWork
{
    void Set(int, float, bool);
public:
    void FUN_00a0b520();
};
// @fnv 0x0078bc80
void LoadingStatsMenu::ApplySettings(LoadingStatsSettings* settings)
{
    reinterpret_cast<::FUN_00a012d0_t *>((container))->FUN_00a012d0(0xfa1, float(left), true);
    reinterpret_cast<::FUN_00a012d0_t *>((container))->FUN_00a012d0(0xfb1, float(right - left), true);
    reinterpret_cast<::FUN_00a012d0_t *>((container))->FUN_00a012d0(0xfa2, float(top), true);
    reinterpret_cast<::FUN_00a012d0_t *>((container))->FUN_00a012d0(0xfb0, float(bottom - top), true);
    firstStats->Set(0xfb9, settings->first.iVisible);
    reinterpret_cast<::FUN_00a012d0_t *>((firstStats))->FUN_00a012d0(0xfb2, settings->first.fRed, true);
    reinterpret_cast<::FUN_00a012d0_t *>((firstStats))->FUN_00a012d0(0xfb3, settings->first.fGreen, true);
    reinterpret_cast<::FUN_00a012d0_t *>((firstStats))->FUN_00a012d0(0xfb4, settings->first.fBlue, true);
    secondStats->Set(0xfb9, settings->second.iVisible);
    reinterpret_cast<::FUN_00a012d0_t *>((firstStats))->FUN_00a012d0(0xfb2, settings->second.fRed, true);
    reinterpret_cast<::FUN_00a012d0_t *>((firstStats))->FUN_00a012d0(0xfb3, settings->second.fGreen, true);
    reinterpret_cast<::FUN_00a012d0_t *>((firstStats))->FUN_00a012d0(0xfb4, settings->second.fBlue, true);
    float spacing = reinterpret_cast<::TileListBoxCalls *>((container))->GetFloat(0xfb0) / settings->second.count;
    float y = 0.0f;
    NiTListItem<Tile*>* secondPos = ((::NiTListItem< ::Tile *> *)(reinterpret_cast<::Callees *>(&(firstStats->children))->FUN_00726070()));
    NiTListItem<Tile*>* pos2 = ((::NiTListItem< ::Tile *> *)(reinterpret_cast<::Callees *>(&(secondStats->children))->FUN_00726070()));
    unsigned int uiIndex = 1;
    while (secondPos && pos2)
    {
        Tile* firstTile = firstStats->children.GetPrev(secondPos);
        Tile* secondTile = secondStats->children.GetPrev(pos2);
        if (firstTile && secondTile)
        {
            bool visible = true;
            if (uiIndex <= settings->second.count)
            {
                reinterpret_cast<::FUN_00a012d0_t *>((firstTile))->FUN_00a012d0(0xfa2, y, true);
                reinterpret_cast<::FUN_00a012d0_t *>((secondTile))->FUN_00a012d0(0xfa2, y, true);
                y += spacing;
                reinterpret_cast<::FUN_00a07530_shell *>((static_cast<LoadingStatsTile*>(firstTile)))->FUN_00a07530(8);
                reinterpret_cast<::FUN_00a07530_shell *>((static_cast<LoadingStatsTile*>(secondTile)))->FUN_00a07530(8);
                ++uiIndex;
            }
            else
            {
                visible = false;
            }
            firstTile->Set(0xfa3, int(visible));
            secondTile->Set(0xfa3, int(visible));
        }
    }
    reinterpret_cast<::FUN_00a012d0_t *>((container))->FUN_00a012d0(0xffa, settings->first.fAlpha, true);
    reinterpret_cast<::TileWork *>((container))->FUN_00a0b520();
}
struct WorkTileList
{
};
struct Options
{
    int unk00;
    int unk04;
    int unk08;
    int unk0c;
    int unk10;
    float alpha;
    int font;
    float value1;
    float value2;
    float value3;
    unsigned align;
};
struct MenuWork
{
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
    int unk2c;
    int unk30;
    TileWork* secondary;
    int unk38;
    int unk3c;
    int unk40;
    int unk44;
    int unk48;
    int unk4c;
    int unk50;
    int unk54;
    int unk58;
    int unk5c;
    int unk60;
    int unk64;
    int unk68;
    int unk6c;
    int unk70;
    int unk74;
    int unk78;
    int unk7c;
    int unk80;
    int unk84;
    int unk88;
    int unk8c;
    int unk90;
    TileWork* primary;
    int unk98;
    int unk9c;
    int unka0;
    int unka4;
    int unka8;
    int unkac;
    int unkb0;
    int unkb4;
    int unkb8;
    int unkbc;
    int left;
    int top;
    int right;
    int unkcc;
    int unkd0;
    int unkd4;
    int unkd8;
    WorkTileList tiles;
    void UpdateMenuTiles(Options*);
};
// Measures the selected font, configures the primary and secondary tiles from options, sets the primary tile's alpha and finishes it.
// @fnv 0x0078bf80
void MenuWork::UpdateMenuTiles(Options* options)
{
    float fontHeight = reinterpret_cast<::FUN_00759450_shell *>((((::FontMgr *)(::FontManager::Instance()))->fonts[options->font]))->FUN_00759450();
    void* position = ((void *)(::FUN_00559450((int *)&(tiles))));
    while (position)
    {
        TileWork* tile = ((::TileWork *)(reinterpret_cast<::ListStandIn *>(&(tiles))->FUN_0057cbe0((int **)&(position))));
        if (tile)
        {
            if (tile == primary)
            {
                float offset = 0.0f;
                switch (options->align)
                {
                case 1:
                    offset = left;
                    break;
                case 2:
                    offset = left + (right - left) / 2.0;
                    break;
                case 4:
                    offset = right;
                    break;
                }
                reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(0xfa1, offset, true);
                reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(0xfb1, float(right - left), true);
                reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(0xfba, reinterpret_cast<::TileListBoxCalls *>((tile))->GetFloat(0xfb1), true);
                reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(0xfa2, float(top), true);
                reinterpret_cast<::Tile *>((tile))->Set(0xfb9, options->font);
                reinterpret_cast<::Tile *>((tile))->Set(0xfb7, options->align);
                reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(0xfb2, options->value1, true);
                reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(0xfb3, options->value2, true);
                reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(0xfb4, options->value3, true);
                reinterpret_cast<::Tile *>((tile))->Set(0xff5, -1);
                reinterpret_cast<::FUN_00a07530_shell *>((tile))->FUN_00a07530(8);
            }
            else if (tile == secondary)
            {
                float width = float(right - left);
                Extent extent;
                ((::FontMgr *)(::FontManager::Instance()))->Measure(&extent, ((const char *)(reinterpret_cast<::StartMenu *>((((SettingT_GameSettingCollection_*)&g_011d40f0)))->GetMenuTitle())),
                                        options->font, width, 0);
                float height = extent.y;
                reinterpret_cast<::FUN_00a012d0_t *>((tile))->FUN_00a012d0(0xfa2, height, true);
            }
        }
    }
    reinterpret_cast<::FUN_00a012d0_t *>((primary))->FUN_00a012d0(0xffa, options->alpha, true);
    primary->FUN_00a0b520();
}

struct TileVT
{
    virtual void Unk_00();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual unsigned int GetType();
};
struct TileImage3D
{
};
struct FUN_0078ce10_shell
{
    char pad00[0x58];
    Tile* m_pkInvertedTile;
    char pad5c[0xac - 0x5c];
    Tile* m_pkSkipTile;
    void SetTileAlpha(Tile* pkTile, float fAlpha);
};

// @fnv 0x0078ce10
void FUN_0078ce10_shell::SetTileAlpha(Tile* pkTile, float fAlpha)
{
    if (!pkTile)
        return;
    if (pkTile == m_pkSkipTile)
        return;
    fAlpha = FUN_0040ebd0(fAlpha, 1.0f);
    fAlpha = FUN_00404010(fAlpha, 0.0f);
    if (((TileVT*)pkTile)->GetType() == 0x388)
    {
        reinterpret_cast<::FUN_0078cf10_Class *>(this)->SetAlphaRecursive((::NiAVObject *)(::NiNode *)(((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((((TileImage3D*)pkTile)))->FUN_0056c7f0()))), fAlpha);
        return;
    }
    if (pkTile == m_pkInvertedTile)
        fAlpha = 1.0f - fAlpha;
    reinterpret_cast<::FUN_00a012d0_t *>((pkTile))->FUN_00a012d0(0xfa9, fAlpha * 255.0, true);
    DAT_011a0295 = true;
    void* pPos = ((void *)(::FUN_00559450((int *)(((TileList*)((char*)pkTile + 4))))));
    while (pPos)
        SetTileAlpha(((::Tile *)(reinterpret_cast<::ListStandIn *>((((TileList*)((char*)pkTile + 4))))->FUN_0057cbe0((int **)&(pPos)))), fAlpha);
}

namespace fnv_0078bb60 {
extern bool DAT_011a0296;
struct PerkEntryX : BGSPerkEntry
{
};
struct LoadingMenuX : LoadingMenu
{
    void FUN_0078bb60(BGSPerkEntry* entry);
};
// Applies the selected perk entry's settings to the loading menu tiles, XP bar, or menu tiles based on its type, then clears DAT_011a0296.
// @fnv 0x0078bb60
void LoadingMenuX::FUN_0078bb60(BGSPerkEntry* entry)
{
    if (!reinterpret_cast<::LoadingMenu *>(this)->GetFloat(6))
        return;
    if (entry == 0)
    {
        if (currentCandidate)
            entry = ((::BGSPerkEntry *)(new ((void *)(currentCandidate)) ::Vec3()));
        else
            entry = ((::BGSPerkEntry *)(new ((void *)&(candidates)) ::Vec3()));
        if (entry == 0)
            return;
    }
    if (((void *)(reinterpret_cast<::BGSCameraPath *>((((PerkEntryX*)entry)))->GetPrevPath())))
    {
        int x = ::FUN_0078bc60((int)(((PerkEntryX*)entry)));
        reinterpret_cast<::FUN_0078b9b0_shell *>(this)->FUN_0078b9b0((void *)(x));
        switch (reinterpret_cast<::FUN_005a7130_shell *>((((PerkEntryX*)entry)))->FUN_005a7130())
        {
        case 4:
            reinterpret_cast<::LoadingStatsMenu *>(this)->ApplySettings((::LoadingStatsSettings *)(x));
            break;
        case 1:
            reinterpret_cast<::fnv_0078c210::LoadingMenuX *>(this)->ApplyXPBarSettings((::fnv_0078c210::LoadingTileSettingsX *)(x));
            break;
        case 3:
            reinterpret_cast<::LoadingMenuTips *>(this)->ApplySettingsToTiles((::LoadingTileSettings *)(x));
            break;
        case 2:
            reinterpret_cast<::MenuWork *>(this)->UpdateMenuTiles((::Options *)(x));
            break;
        }
    }

    DAT_011a0296 = false;
}
}  // namespace fnv_0078bb60

namespace s78cc50 {

struct Tile
{
};

struct TileMenu
{
};

struct VATSCamera
{
    int FUN_0078cdf0();
};



struct FadeMenu
{
    int unk000;
    Tile* m_pkTile;
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
    TileMenu* m_pkMenu;
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
    int unk100;
    int unk104;
    int unk108;
    int unk10c;
    int unk110;
    int unk114;
    int unk118;
    int unk11c;
    int unk120;
    int unk124;
    int unk128;
    int unk12c;
    int unk130;
    int unk134;
    int unk138;
    int unk13c;
    int unk140;
    int unk144;
    int unk148;
    int unk14c;
    int unk150;
    int unk154;
    int unk158;
    int unk15c;
    int unk160;
    int unk164;
    int unk168;
    int unk16c;
    int unk170;
    int unk174;
    int unk178;
    int unk17c;
    int unk180;
    int unk184;
    int unk188;
    int unk18c;
    int unk190;
    int unk194;
    int unk198;
    int unk19c;
    int unk1a0;
    int unk1a4;
    int unk1a8;
    int unk1ac;
    int unk1b0;
    int unk1b4;
    int unk1b8;
    int unk1bc;
    int unk1c0;
    int unk1c4;
    int unk1c8;
    int unk1cc;
    int unk1d0;
    int unk1d4;
    int unk1d8;
    int unk1dc;
    int unk1e0;
    unsigned int m_uiEndTime;
    int unk1e8;
    int unk1ec;
    int unk1f0;
    int unk1f4;
    int unk1f8;
    int unk1fc;
    int unk200;
    int unk204;
    int unk208;
    int unk20c;
    int unk210;
    int unk214;
    int unk218;
    int unk21c;
    int unk220;
    int unk224;
    int unk228;
    int unk22c;
    int unk230;
    int unk234;
    int unk238;
    int unk23c;
    int unk240;
    int unk244;
    int unk248;
    int unk24c;
    int unk250;
    int unk254;
    int unk258;
    int unk25c;
    int unk260;
    int unk264;
    int unk268;
    int unk26c;
    int unk270;
    int unk274;
    int unk278;
    int unk27c;
    int unk280;
    int unk284;
    int unk288;
    int unk28c;
    int unk290;
    int unk294;
    int unk298;
    int unk29c;
    int unk2a0;
    int unk2a4;
    int unk2a8;
    int unk2ac;
    int unk2b0;
    int unk2b4;
    int unk2b8;
    int unk2bc;
    int unk2c0;
    int unk2c4;
    int unk2c8;
    int unk2cc;
    int unk2d0;
    int unk2d4;
    int unk2d8;
    int unk2dc;
    int unk2e0;
    int unk2e4;
    int unk2e8;
    int unk2ec;
    int unk2f0;
    int unk2f4;
    int unk2f8;
    int unk2fc;
    int unk300;
    int unk304;
    int unk308;
    int unk30c;
    int unk310;
    int unk314;
    int unk318;
    int unk31c;
    int unk320;
    int unk324;
    int unk328;
    int unk32c;
    int unk330;
    int unk334;
    int unk338;
    int unk33c;
    int unk340;
    int unk344;
    int unk348;
    int unk34c;
    int unk350;
    int unk354;
    int unk358;
    int unk35c;
    int unk360;
    int unk364;
    int unk368;
    int unk36c;
    int unk370;
    int unk374;
    int unk378;
    int unk37c;
    int unk380;
    int unk384;
    int unk388;
    int unk38c;
    int unk390;
    int unk394;
    int unk398;
    int unk39c;
    int unk3a0;
    int unk3a4;
    int unk3a8;
    int unk3ac;
    int unk3b0;
    int unk3b4;
    int unk3b8;
    int unk3bc;
    int unk3c0;
    int unk3c4;
    int unk3c8;
    int unk3cc;
    int unk3d0;
    int unk3d4;
    int unk3d8;
    int unk3dc;
    int unk3e0;
    int unk3e4;
    int unk3e8;
    int unk3ec;
    int unk3f0;
    int unk3f4;
    int unk3f8;
    int unk3fc;
    int unk400;
    int unk404;
    int unk408;
    int unk40c;
    int unk410;
    int unk414;
    int unk418;
    int unk41c;
    int unk420;
    int unk424;
    int unk428;
    int unk42c;
    int unk430;
    int unk434;
    int unk438;
    int unk43c;
    int unk440;
    int unk444;
    int unk448;
    int unk44c;
    int unk450;
    int unk454;
    int unk458;
    int unk45c;
    int unk460;
    int unk464;
    int unk468;
    int unk46c;
    int unk470;
    int unk474;
    int unk478;
    int unk47c;
    int unk480;
    int unk484;
    int unk488;
    int unk48c;
    int unk490;
    int unk494;
    int unk498;
    int unk49c;
    int unk4a0;
    int unk4a4;
    int unk4a8;
    int unk4ac;
    int unk4b0;
    int unk4b4;
    int unk4b8;
    int unk4bc;
    int unk4c0;
    int unk4c4;
    int unk4c8;
    int unk4cc;
    int unk4d0;
    int unk4d4;
    int unk4d8;
    int unk4dc;
    int unk4e0;
    int unk4e4;
    int unk4e8;
    int unk4ec;
    int unk4f0;
    int unk4f4;
    int unk4f8;
    int unk4fc;
    int unk500;
    int unk504;
    int unk508;
    int unk50c;
    int unk510;
    int unk514;
    int unk518;
    int unk51c;
    int unk520;
    int unk524;
    int unk528;
    int unk52c;
    int unk530;
    int unk534;
    int unk538;
    int unk53c;
    int unk540;
    int unk544;
    int unk548;
    int unk54c;
    int unk550;
    int unk554;
    int unk558;
    int unk55c;
    int unk560;
    int unk564;
    int unk568;
    int unk56c;
    int unk570;
    int unk574;
    int unk578;
    int unk57c;
    int unk580;
    int unk584;
    int unk588;
    int unk58c;
    int unk590;
    int unk594;
    int unk598;
    int unk59c;
    int unk5a0;
    int unk5a4;
    int unk5a8;
    int unk5ac;
    int unk5b0;
    int unk5b4;
    int m_iFadeCount;

    void FUN_0078cc50();
};

// @fnv 0x0078cc50
void FadeMenu::FUN_0078cc50()
{
    static float s_fDuration = reinterpret_cast<::TileListBoxCalls *>((m_pkTile))->GetFloat(0xfc1) * 1000.0;

    if (m_uiEndTime == 0)
    {
        if ((*reinterpret_cast<::s78cc50::VATSCamera * *>(&::g_osGlobals))->FUN_0078cdf0() || ::DAT_011a0294)
        {
            reinterpret_cast<::TileImage *>((m_pkMenu))->SetTexture((::NiAVObject *)((*reinterpret_cast<::s78cc50::VATSCamera * *>(&::g_osGlobals))->FUN_0078cdf0()));
            m_uiEndTime = (unsigned int)(((unsigned int)(::FUN_00457fe0())) + s_fDuration);
        }
        else
        {
            m_uiEndTime = ((unsigned int)(::FUN_00457fe0()));
        }
    }
    if (((unsigned int)(::FUN_00457fe0())) < m_uiEndTime)
    {
        unsigned int uiRemaining = m_uiEndTime - ((unsigned int)(::FUN_00457fe0()));
        reinterpret_cast<::FUN_0078ce10_shell *>(this)->SetTileAlpha((::Tile *)(m_pkTile), 1.0f - uiRemaining / s_fDuration);
    }
    else
    {
        reinterpret_cast<::FUN_0078ce10_shell *>(this)->SetTileAlpha((::Tile *)(m_pkTile), 1.0f);
        reinterpret_cast<::LoadingMenu *>(this)->SetFloatFlag(4, 0);
        m_iFadeCount++;
    }
}

}


struct FUN_0078aa90_shell : LoadingMenu
{
    bool UpdateLoadingScreen();
};
// If DAT_011a0294 is set, GetFloat(0) is zero, and p3dtile->FUN_0078a1f0() is false, advance currentCandidate and apply the loading texture.
// @fnv 0x0078aa90
bool FUN_0078aa90_shell::UpdateLoadingScreen()
{
    Tile* p3dtile = m_pTiles[0];
    if (DAT_011a0294 && !GetFloat(0) && !::FUN_0078a1f0((::FUN_0078a1f0_this *)(p3dtile)))
    {
        while (reinterpret_cast<::Callees *>((currentCandidate))->FUN_00726070())
            currentCandidate = (BSSimpleList<BGSPerkEntry*>*)reinterpret_cast<::Callees *>((currentCandidate))->FUN_00726070();
        reinterpret_cast<::LoadingMenuX *>((((LoadingMenuS*)this)))->ApplyLoadingScreenTexture((::TileShaderProperty *)(void *)(0));
        nextTipTime = ((unsigned int)(::FUN_00457fe0()));
        return true;
    }
    else
    {
        return false;
    }
}

struct LoadVisibilityMenu : LoadingMenu
{
    void FUN_0078b3f0(TESLoadScreen*, bool);
};
// Clears and rebuilds the loading screen list from settings or gathered entries, adds a fallback entry, refreshes the menu and selects the first entry.
// @fnv 0x0078a5a0
void FUN_0078a5a0_cls::UpdateLoadingScreens()
{
    bool cleared = false;
    if (!((ScreenList*)&unk1d0)->Empty())
    {
        ::FUN_0078a940((char *)this);
        cleared = true;
    }
    reinterpret_cast<::LoadingMenu *>(this)->SetFloatFlag(5, FUN_0070edf0() || (unsigned char)reinterpret_cast<::FUN_00678ce0_shell *>(((*reinterpret_cast<::DurationData * *>(&::g_osGlobals))))->FUN_00678ce0());
    if (DAT_011a0294 && !FUN_0070edf0())
    {
        int index = 0;
        if (((int)(::FUN_0044a670(((const char *)(reinterpret_cast<::StartMenu *>((((SettingProxy*)&g_011de740)))->GetMenuTitle()))))))
            index = 3;
        for (; index < 5; ::PostIncrementInt(&index))
        {
            const char* folder = index == 4 ? "Main" : "Loading";
            ::FUN_00406f60((::FUN_00406f90_this *)&(m_kLoadingScreenTip), "Interface\\%s\\%s.dds", folder, ((const char *)(reinterpret_cast<::StartMenu *>(&(screenNames[index]))->GetMenuTitle())));
            ScreenEntry* entry = new ScreenEntry;
            reinterpret_cast<::TESFullName *>(&(entry->path))->SetFullName(m_kLoadingScreenTip);
            reinterpret_cast<::TESForm *>((entry))->NotifySaveLoadGameOfFormChange();
            reinterpret_cast<::Callees *>((((ScreenList*)&unk1d0)))->FUN_00905820((void *)&(entry));
        }
    }
    else
    {
        ScreenArray screenArray;
        Gather(screenArray);
        Build(screenArray);
        if (unk1e8 && ((ScreenList*)&unk1d0)->Count() < *((unsigned int *)&(::FUN_0043d4d0((int *)(((SettingProxy*)&g_011da138))))) && !FUN_0078a930())
        {
            unk1e8 = 0;
            Gather(screenArray);
            Build(screenArray);
        }
    }
    if (((ScreenList*)&unk1d0)->Empty())
    {
        ::FUN_00406f60((::FUN_00406f90_this *)&(m_kLoadingScreenTip), "Interface\\Loading\\%s.dds", ((const char *)(reinterpret_cast<::StartMenu *>(&(screenNames[0]))->GetMenuTitle())));
        ScreenEntry* fallback = new ScreenEntry;
        reinterpret_cast<::TESFullName *>(&(fallback->path))->SetFullName(m_kLoadingScreenTip);
        reinterpret_cast<::TESForm *>((fallback))->NotifySaveLoadGameOfFormChange();
        ((ScreenList*)&unk1d0)->Add(fallback);
    }
    if (cleared && !::FUN_0078a1f0((::FUN_0078a1f0_this *)(((Tile*)unk028))))
    {
        ApplyLoadingScreenTexture(0);
        reinterpret_cast<::LoadingMenu *>(this)->UpdateLoadingScreenTip();
    }
    reinterpret_cast<::LoadingMenu *>(this)->SetFloatFlag(7, true);
    unk1dc = (int)*((::ScreenEntry **)(new ((void *)(((ScreenList*)&unk1d0))) ::Vec3()));
    reinterpret_cast<::LMStandIn *>(this)->FUN_0078bb40();
    reinterpret_cast<::LoadVisibilityMenu *>(this)->FUN_0078b3f0((::TESLoadScreen *)(::ScreenEntry *)((ScreenEntry*)unk1dc), true);
}

// For a selected screen with bShow true, dispatches settings by screen type; otherwise passes bShow to all four methods.
// @fnv 0x0078b3f0
void LoadVisibilityMenu::FUN_0078b3f0(TESLoadScreen* pLoadScreen, bool bShow)
{
    if (!GetFloat(6))
    {
        return;
    }
    if (!pLoadScreen)
    {
        if (currentCandidate)
        {
            pLoadScreen = (TESLoadScreen*)((::BGSPerkEntry *)(new ((void *)(currentCandidate)) ::Vec3()));
        }
        else
        {
            pLoadScreen = (TESLoadScreen*)((::BGSPerkEntry *)(new ((void *)&(candidates)) ::Vec3()));
        }
        if (!pLoadScreen)
        {
            return;
        }
    }
    if (pLoadScreen && bShow)
    {
        switch (reinterpret_cast<::FUN_005a7130_shell *>((pLoadScreen))->FUN_005a7130())
        {
        case 2:
            reinterpret_cast<::fnv_0078b6a0::LM0078b6a0 *>(this)->FUN_0078b6a0(bShow);
            reinterpret_cast<::LM0078b650 *>(this)->FUN_0078b650(!bShow);
            reinterpret_cast<::S78b *>(this)->FUN_0078b6f0(!bShow);
            reinterpret_cast<::fnv_0078b7c0::LM0078b7c0 *>(this)->FUN_0078b7c0(!bShow);
            break;
        case 4:
            reinterpret_cast<::fnv_0078b6a0::LM0078b6a0 *>(this)->FUN_0078b6a0(!bShow);
            reinterpret_cast<::LM0078b650 *>(this)->FUN_0078b650(bShow);
            reinterpret_cast<::S78b *>(this)->FUN_0078b6f0(!bShow);
            reinterpret_cast<::fnv_0078b7c0::LM0078b7c0 *>(this)->FUN_0078b7c0(!bShow);
            break;
        case 3:
            reinterpret_cast<::fnv_0078b6a0::LM0078b6a0 *>(this)->FUN_0078b6a0(!bShow);
            reinterpret_cast<::LM0078b650 *>(this)->FUN_0078b650(!bShow);
            reinterpret_cast<::S78b *>(this)->FUN_0078b6f0(bShow);
            reinterpret_cast<::fnv_0078b7c0::LM0078b7c0 *>(this)->FUN_0078b7c0(!bShow);
            break;
        case 1:
            reinterpret_cast<::fnv_0078b6a0::LM0078b6a0 *>(this)->FUN_0078b6a0(!bShow);
            reinterpret_cast<::LM0078b650 *>(this)->FUN_0078b650(!bShow);
            reinterpret_cast<::S78b *>(this)->FUN_0078b6f0(!bShow);
            reinterpret_cast<::fnv_0078b7c0::LM0078b7c0 *>(this)->FUN_0078b7c0(bShow);
            break;
        default:
            reinterpret_cast<::fnv_0078b6a0::LM0078b6a0 *>(this)->FUN_0078b6a0(false);
            reinterpret_cast<::LM0078b650 *>(this)->FUN_0078b650(false);
            reinterpret_cast<::S78b *>(this)->FUN_0078b6f0(false);
            reinterpret_cast<::fnv_0078b7c0::LM0078b7c0 *>(this)->FUN_0078b7c0(false);
            break;
        }
    }
    else
    {
        reinterpret_cast<::fnv_0078b6a0::LM0078b6a0 *>(this)->FUN_0078b6a0(bShow);
        reinterpret_cast<::LM0078b650 *>(this)->FUN_0078b650(bShow);
        reinterpret_cast<::S78b *>(this)->FUN_0078b6f0(bShow);
        reinterpret_cast<::fnv_0078b7c0::LM0078b7c0 *>(this)->FUN_0078b7c0(bShow);
    }
}

namespace fnv_00788ab0 {
struct LoadingResetTileState
{
};
struct S00788ab0_AfaShell
{
};
struct S00788ab0_LoadingMenu
{
};
class S00788ab0_StartMenu
{
  public:
    enum S00788ab0_Flag
    {
        Flag1 = 1
    };
    virtual ~S00788ab0_StartMenu();
    bool IsFlagSet(S00788ab0_Flag);
};
struct S00788ab0_MenuTileQuery
{
};
struct S00788ab0_OSQuery
{
};
struct S00788ab0_InterfaceQuery
{
};
struct S00788ab0_VisibleTile
{
};
struct S00788ab0_LoadingSetup : LoadingMenu
{
    void FUN_00788ab0(int);
};
// When GetFloat(3) is nonzero, updates timers and menu state, configures tiles, and assigns value to extraCandidates.
// @fnv 0x00788ab0
void S00788ab0_LoadingSetup::FUN_00788ab0(int aiExtraCandidates)
{
    if (GetFloat(3))
    {
        ::LoadingMenu::UpdateLoadingScreenThread();
        m_uiFirstStateValue = ((unsigned int)(::FUN_00457fe0())) - 4000;
        if (DAT_011d8907 || reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>((::g_BGSSaveLoadGame))->FUN_0042ce10())
        {
            S00788ab0_StartMenu* menu = ((::fnv_00788ab0::S00788ab0_StartMenu *)(reinterpret_cast<::FUN_00a03c90_shell *>((((::fnv_00788ab0::S00788ab0_MenuTileQuery *)(::FUN_00a09030(::FUN_0070ede0())))))->FUN_00a03c90()));
            if (menu && !menu->IsFlagSet(S00788ab0_StartMenu::Flag1))
            {
                delete menu;
            }
        }
        if (((bool)(reinterpret_cast<::FUN_00678ce0_shell *>((((S00788ab0_OSQuery*)g_osGlobals)))->FUN_00678ce0())))
        {
            reinterpret_cast<::FUN_0078afa0_shell *>((((S00788ab0_AfaShell*)this)))->FUN_0078afa0(false);
        }
        else
        {
            reinterpret_cast<::FUN_0078afa0_shell *>((((S00788ab0_AfaShell*)this)))->FUN_0078afa0(true);
            reinterpret_cast<::LoadingMenu *>(this)->RefreshLoadingScreen();
        }
        extraCandidates = aiExtraCandidates;
        reinterpret_cast<::FUN_0078a5a0_cls *>(this)->UpdateLoadingScreens();
        extraCandidates = aiExtraCandidates;
        nextTipTime = ((unsigned int)(::FUN_00457fe0()));
        ++m_uiSecondStateValue;
        reinterpret_cast<::FUN_0078a280_shell *>((((S00788ab0_LoadingMenu*)this)))->UpdateLoadingScreenText(0);
        ::FUN_0078a9f0((char*)this);
        reinterpret_cast<::LoadingMenuX *>((((S00788ab0_LoadingMenu*)this)))->ApplyLoadingScreenTexture((::TileShaderProperty *)(0));
        reinterpret_cast<::LoadingMenu *>(this)->UpdateLoadingScreenTip();
        ++m_uiSecondStateValue;
        reinterpret_cast<::FUN_0078a280_shell *>((((S00788ab0_LoadingMenu*)this)))->UpdateLoadingScreenText(0);
        ::FUN_0078a9f0((char*)this);
        reinterpret_cast<::LoadingMenuX *>((((S00788ab0_LoadingMenu*)this)))->ApplyLoadingScreenTexture((::TileShaderProperty *)(0));
        reinterpret_cast<::LoadingMenu *>(this)->UpdateLoadingScreenTip();
        reinterpret_cast<::LoadingMenu *>((((LoadingResetTileState*)this)))->SetFloatFlag((*(int *)&(const ::LoadingMenu::TileIndex &)((TileIndex)3)), false);
        ::FUN_004a0370((char*)((void *)(::FUN_0043c4b0())));
        if (!reinterpret_cast<::sa040a0::Owner *>((((S00788ab0_VisibleTile*)m_pTiles[11])))->IsAllChildrenFlag0())
        {
            m_pTiles[11]->Set(4003, 1);
            reinterpret_cast<::FUN_0078a230_shell *>((((S00788ab0_LoadingMenu*)this)))->FUN_0078a230();
        }
        ((::Tile *)(reinterpret_cast<::FUN_0045cd60_shell *>((((S00788ab0_InterfaceQuery*)((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))))->FUN_0045cd60()))->Set(4003, 0);
        ::fnv_00a04200::FUN_00a04200(true);
        reinterpret_cast<::fnv_004a03c0::DD *>(((char*)((void *)(::FUN_0043c4b0()))))->FUN_004a03c0();
        ::DAT_011a0295 = true;
        ::BSSystemUtility::GetRandomGenerator();
    }
}
}  // namespace fnv_00788ab0

#include "generated/data/fallout/interface/menus/loadingmenu.inc"
