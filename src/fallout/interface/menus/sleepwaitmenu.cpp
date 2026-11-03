
// src/fallout/interface/menus/sleepwaitmenu.cpp - unit created 2026-10-16 from the whole-binary attribution (360 source path: d:/_fallout3/platforms/common/code/fallout/interface/menus/sleepwaitmenu.cpp).
// Functions are listed by their @fnv annotations; compile flags inferred from the PC code.

#include <cctype>
#include "fnv/decl/Calendar.h"
#include "fnv/decl/CalendarProxy.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_005c1a00.h"
#include "fnv/decl/FUN_005cde20Class.h"
#include "fnv/decl/FUN_007abdb0_shell.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_00974fc0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a01290_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FaderManager.h"
#include "fnv/decl/FakeSaveMgr.h"
#include "fnv/decl/HotkeyWheelDisplay.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/PlayerCharacter.h"
#include "fnv/decl/ProcessListsShell.h"
#include "fnv/decl/ProcessListsSub.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/TopicMenuController.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_00455490__Q455490TES.h"
#include "fnv/decl/fnv_0094df80__PlayerCharacter_Cand.h"
#include "fnv/decl/fnv_00969c30__HardcorePlayer.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a1c520__FUN_00a1c520.h"
#include "fnv/symbols_00401000.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_004d1000.h"
#include "fnv/symbols_00559000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_005c7000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_007c0000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_01016000.h"
#include "fnv/symbols_0104a000.h"
#include "fnv/symbols_01070000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011e0000.h"
#include "fnv/symbols_011f6000.h"
struct SleepWaitMenu
{
    int FUN_007bfbc0();
};

// @fnv 0x007bfbc0
int SleepWaitMenu::FUN_007bfbc0()
{
    return 0x3f4;
}

namespace fnv_007bfbd0 {
struct SleepWaitMenu;


struct SleepWaitMenu
{
    void* FUN_007bfbd0(unsigned int flags);
    void* FUN_007bfc00();
};

void* SleepWaitMenu::FUN_007bfc00()
{
    return this;
}

// Returns this, and if bit 0 of flags is set, deallocates this before returning it.
// @fnv 0x007bfbd0
void* SleepWaitMenu::FUN_007bfbd0(unsigned int flags)
{
    FUN_007bfc00();
    if (flags & 1)
        ::FUN_00401030(this);
    return this;
}
}  // namespace fnv_007bfbd0

struct BSStringTChar
{
    char* data;
    unsigned short length, capacity;
    ~BSStringTChar();
};
struct Time
{
    BSStringTChar FormatDate();
};
struct Setting
{
};
struct Tile
{
public:
    void Set(int, int);
public:
    static float GetInterfaceScale();
};
struct Menu
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28, unk2C, unk30;
    Tile* tile;
    void UpdateClockText();
public:
    void SetMenuVisibility(bool);
};
// Builds a 12-hour clock string from the current game time and passes it to the tile via FUN_00a01350.
// @fnv 0x007c0000
void Menu::UpdateClockText()
{
    char szClockText[260];
    int hour;
    {
        float time = reinterpret_cast<::Calendar *>(&((*reinterpret_cast<::Time *>(&::g_011de7b8))))->GetGameTime();
        hour = (int)time;
        {
            int minute = (int)((time - hour) * 60.0);
            if (time >= 0.0 && time < 1.0)
                hour = 12;
            else if (time >= 13.0)
                hour -= 12;
            ::FUN_00406d00(szClockText, 260, "%s, %s, %d:%02d %s", reinterpret_cast<::CalendarProxy *>(&((*reinterpret_cast<::Time *>(&::g_011de7b8))))->GetDayName(),
                      ((const char *)(::FUN_00559450((int *)&((*reinterpret_cast<::Time *>(&::g_011de7b8)).FormatDate())))), hour, minute,
                      time < 12.0 ? ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting *>(&::g_011d24fc))))->GetMenuTitle())) : ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting *>(&::g_011d27f0))))->GetMenuTitle())));
        }
    }
    reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((tile))->FUN_00a01350(0xfc4, (char *)(szClockText), true);
}

namespace fnv_007c01b0 {
struct BGSSaveLoadGame
{
};
struct ProcessLists
{
};
struct Interface
{
};
struct Tile
{
};
struct MenuState
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C;
    int unk20, unk24, unk28, unk2C, unk30, unk34, unk38, unk3C;
    int unk40;
    char unk44;
    bool active;
};

// @fnv 0x007c01b0
void FUN_007c01b0()
{
    if ((*reinterpret_cast<::fnv_007c01b0::MenuState * *>(&::DAT_011da920)))
    {
        if (!reinterpret_cast<::fnv_0042ce10::FUN_0042ce10_shell *>(((*reinterpret_cast<::fnv_007c01b0::BGSSaveLoadGame * *>(&::g_BGSSaveLoadGame))))->FUN_0042ce10())
            reinterpret_cast<::ProcessListsSub *>(&((*reinterpret_cast<::fnv_007c01b0::ProcessLists *>(&::g_011e0e80))))->UpdateActor3D();
        if ((*reinterpret_cast<::fnv_007c01b0::MenuState * *>(&::DAT_011da920))->active)
            reinterpret_cast<::FaderManager *>(((*reinterpret_cast<::fnv_007c01b0::Interface * *>(&::DAT_011d8804))))->StopFader((::FADER_ENUM)(0), 0);
        reinterpret_cast<::Tile *>((((::fnv_007c01b0::Tile *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::fnv_007c01b0::MenuState * *>(&::DAT_011da920))))->FUN_00726070()))))->Set(0x1772, 1);
        reinterpret_cast<::FUN_00a1d910_shell *>(((*reinterpret_cast<::fnv_007c01b0::MenuState * *>(&::DAT_011da920))))->FUN_00a1d910();
    }
}
}  // namespace fnv_007c01b0


struct MenuBaseObject
{
    virtual void v00();

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
    int unk34;
    int unk38;
    int unk3c;

    MenuBaseObject();
    ~MenuBaseObject();
};

struct FUN_007bfb30_cls : MenuBaseObject
{
    virtual void v00();

    float m_f40;
    unsigned char m_b44;
    unsigned char unk45;
    unsigned char m_b46;
    unsigned char unk47;
    float m_f48;

    FUN_007bfb30_cls();
};

// Initializes m_f40, m_b44, m_f48 and m_b46 to zero and stores the result of FUN_00a01860("_current_value") in DAT_011da918.
// @fnv 0x007bfb30
FUN_007bfb30_cls::FUN_007bfb30_cls()
{
    m_f40 = 0.0f;
    m_b44 = 0;
    m_f48 = 0.0f;
    m_b46 = 0;
    (*reinterpret_cast<void * *>(&::fnv_007c0220::DAT_011da918)) = ((void *)(::FUN_00a01860("_current_value")));
}

namespace fnv_007c0220 {
struct DecCfg
{
};
struct DecGate
{
    const unsigned char* FUN_00408d60();
};
struct DecMenuA
{
};
struct DecSnd
{
};
struct DecCtl
{
};
struct DecTile
{
};
struct DecMgr
{
};
struct DecBox
{
};


int __cdecl FUN_00ec62c0();

struct FUN_007c0220_cls
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24;
    int m_slot[6];
    int unk40;
    unsigned char m_44;
    unsigned char m_45;

    void FUN_007c0220(int slot, int value);
};

// @fnv 0x007c0220
void FUN_007c0220_cls::FUN_007c0220(int slot, int value)
{
    if (value == 0 && slot >= 0 && slot < 6)
    {
        value = m_slot[slot];
    }
    switch (slot)
    {
    case 4:
        ::s717280::FUN_00717280(1);
        if ((m_45 && *(*reinterpret_cast<::fnv_007c0220::DecGate *>(&::g_011d89f0)).FUN_00408d60()) || (!m_45 && *(*reinterpret_cast<::fnv_007c0220::DecGate *>(&::g_011d8974)).FUN_00408d60()))
        {
            reinterpret_cast<::FakeSaveMgr *>(((*reinterpret_cast<::fnv_007c0220::DecMenuA * *>(&::DAT_011de134))))->ResetAndUpdate();
        }
        if (m_45 != 0)
        {
            reinterpret_cast<::FaderManager *>(((*reinterpret_cast<::fnv_007c0220::DecSnd * *>(&::DAT_011d8804))))->AddFader((::FADER_ENUM)(0), *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::fnv_007c0220::DecCfg *>(&::originalRuntimeFloatSetting16)))))), {});
        }
        m_44 = 1;
        reinterpret_cast<::Tile *>((reinterpret_cast<DecCtl*>(m_slot[4])))->Set(0xfaf, 0);
        reinterpret_cast<::Tile *>((reinterpret_cast<DecCtl*>(m_slot[1])))->Set(0xfaf, 0);
        reinterpret_cast<::TileListBoxCalls *>((reinterpret_cast<DecTile*>(m_slot[1])))->GetFloat(DAT_011da918);
        reinterpret_cast<::FUN_005c1a00 *>(((*reinterpret_cast<::fnv_007c0220::DecMgr * *>(&::_g_thePlayer))))->Set(FUN_00ec62c0() + 1, {});
        if (m_45 != 0)
        {
            ::TopicMenuController::IncrementMiscStat(0x17);
        }
        if (!::FUN_005c7870((const char *)((*reinterpret_cast<::fnv_007c0220::DecMgr * *>(&::_g_thePlayer)))))
        {
            reinterpret_cast<::FUN_00974fc0_shell *>(&((*reinterpret_cast<::fnv_007c0220::DecBox *>(&::g_011e0e80))))->FUN_00974fc0();
        }
        reinterpret_cast<::ProcessListsShell *>(&((*reinterpret_cast<::fnv_007c0220::DecBox *>(&::g_011e0e80))))->FUN_00975160();
        break;
    case 5:
        ::s717280::FUN_00717280(2);
        reinterpret_cast<::FUN_005c1a00 *>(((*reinterpret_cast<::fnv_007c0220::DecMgr * *>(&::_g_thePlayer))))->Set(0, 0);
        ::fnv_007c01b0::FUN_007c01b0();
        break;
    }
}
}  // namespace fnv_007c0220

namespace fnv_007c04d0 {

struct FUN_007c04d0_sub2c
{
};

struct FUN_007c04d0_sub38
{
};

struct FUN_007c04d0_cls
{
    int unk00, unk04, unk08, unk0C, unk10, unk14, unk18, unk1C, unk20, unk24, unk28;
    FUN_007c04d0_sub2c* m_2c;
    int unk30;
    int unk34;
    FUN_007c04d0_sub38* m_38;

    bool FUN_007c04d0(int a1, int a2);
};

// @fnv 0x007c04d0
bool FUN_007c04d0_cls::FUN_007c04d0(int a1, int aiUnused)
{
    bool done = false;
    if (reinterpret_cast<::FUN_00a01230_shell *>((m_38))->IsTraitNonZero(0xfaf))
    {
        if (a1 == 0xf || a1 == 0x10)
        {
            reinterpret_cast<::FUN_00a012d0_t *>((m_2c))->FUN_00a012d0(::fnv_007c0220::DAT_011da918,
                               reinterpret_cast<::TileListBoxCalls *>((m_2c))->GetFloat(::fnv_007c0220::DAT_011da918) + (a1 == 0xf ? ::DAT_0104a494 : ::DAT_010162c0), {});
            reinterpret_cast<::FUN_00a01290_shell *>((m_2c))->SetTraitAndReset(::FUN_00a01860(::DAT_01070250), 1.0f);
            done = true;
        }
    }
    return done;
}
}  // namespace fnv_007c04d0

namespace fnv_007c03a0 {

struct S_007c03a0_Gauge
{
};
struct S_007c03a0_Flag
{
};

struct S_007c03a0_Menu
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
    S_007c03a0_Gauge* m_gauge;
    Tile* m_tile;
    int unk34;
    S_007c03a0_Flag* m_flag;
    int unk3c;
    int unk40;
    int unk44;
    float m_uiFilterValue;
    void UpdateGaugeDisplay();
};

// When the gauge value for DAT_011da918 changes, updates the cached value, optionally triggers FUN_00706f30(4), and writes a formatted string to the tile.
// @fnv 0x007c03a0
void S_007c03a0_Menu::UpdateGaugeDisplay()
{
    char szText[260];
    if (reinterpret_cast<::TileListBoxCalls *>((m_gauge))->GetFloat(::fnv_007c0220::DAT_011da918) != m_uiFilterValue)
    {
        if (reinterpret_cast<::FUN_00a01230_shell *>((m_flag))->IsTraitNonZero(0xfaf))
        {
            ::FUN_00706f30(4);
        }
        m_uiFilterValue = reinterpret_cast<::TileListBoxCalls *>((m_gauge))->GetFloat(::fnv_007c0220::DAT_011da918);
        ::FUN_00406d00(szText, 0x104, "%d %s", ::FUN_00406d90((float)(m_uiFilterValue + 1.0)),
                  (m_uiFilterValue > 0.0) ? ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting *>(&::g_011d3ae0))))->GetMenuTitle())) : ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::Setting *>(&::g_011d448c))))->GetMenuTitle())));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_tile))->FUN_00a01350(0xfc4, (char *)(szText), true);
    }
}
}  // namespace fnv_007c03a0

struct InputManagerStub
{
};

struct OSGlobalsStub
{
};

struct PlayerStub
{
};

struct TimeGlobalStub
{
};

struct TESStub
{
};

struct TileStub
{
};



struct MenuClass
{
    virtual void v00();
    virtual void v01();
    virtual void v02();
    virtual void v03(int, int);

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
    TileStub* m_tile;
    int unk30;
    int unk34;
    int unk38;
    int unk3c;
    float m_f40;
    unsigned char m_b44;
    unsigned char unk45;
    unsigned char m_b46;
    unsigned char unk47;

    bool FUN_007c0580();
};

// Handles input state flags and, while m_b44 is set, advances m_f40 by the frame time and updates the tile's _current_value and _SetInCode when it reaches 1.0.
// @fnv 0x007c0580
bool MenuClass::FUN_007c0580()
{
    if (reinterpret_cast<::HotkeyWheelDisplay *>((((::InputManagerStub *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::OSGlobalsStub * *>(&::g_osGlobals))))->FUN_00877720()))))->SetHotkeyItem({}, {}))
    {
        m_b46 = 1;
    }
    if ((m_b46 && reinterpret_cast<::HotkeyWheelDisplay *>((((::InputManagerStub *)(reinterpret_cast<::FUN_00877720_shell *>(((*reinterpret_cast<::OSGlobalsStub * *>(&::g_osGlobals))))->FUN_00877720()))))->SetHotkeyItem({}, {})) || (m_b44 && !reinterpret_cast<::PlayerCharacter *>(((*reinterpret_cast<::PlayerStub * *>(&::_g_thePlayer))))->IsSleepingOrResting()))
    {
        if (!::fnv_00703d50::FUN_00703d50())
        {
            v03(5, 0);
            return false;
        }
    }
    if (!m_b44)
    {
        return false;
    }
    m_f40 += reinterpret_cast<::Twin_0084d030 *>(&((*reinterpret_cast<::TimeGlobalStub *>(&::g_timeGlobal))))->GetStoredFloatValue();
    if (m_f40 >= 1.0)
    {
        m_f40 = 0.0f;
    }
    else
    {
        return false;
    }
    reinterpret_cast<::fnv_00455490::Q455490TES *>(((*reinterpret_cast<::TESStub * *>(&::g_TES))))->FUN_00455490();
    if (::FUN_004d1360((char *)((*reinterpret_cast<::PlayerStub * *>(&::_g_thePlayer)))))
    {
        reinterpret_cast<::fnv_00969c30::HardcorePlayer *>(((*reinterpret_cast<::PlayerStub * *>(&::_g_thePlayer))))->FUN_00969c30();
    }
    reinterpret_cast<::fnv_0094df80::PlayerCharacter_Cand *>(((*reinterpret_cast<::PlayerStub * *>(&::_g_thePlayer))))->FUN_0094df80();
    reinterpret_cast<::Tile *>((m_tile))->Set((int)((void *)(::FUN_00a01860("_current_value"))), ((int)(reinterpret_cast<::FUN_005cde20Class *>(((*reinterpret_cast<::PlayerStub * *>(&::_g_thePlayer))))->FUN_005cde20())) - 1);
    reinterpret_cast<::FUN_00a01290_shell *>((m_tile))->SetTraitAndReset((int)((void *)(::FUN_00a01860("_SetInCode"))), 1.0f);
    reinterpret_cast<::Menu *>(this)->UpdateClockText();
    return true;
}

struct SwTile
{
};

struct SwMenu
{
    virtual ~SwMenu();
    virtual void v001();
    virtual void v002();
    virtual void v003();
    virtual void v004();
    virtual void v005();
    virtual void v006();
    virtual void v007();
    virtual void v008();
    virtual void v009();
    virtual void v010();
    virtual void v011();
    virtual void v012();
    virtual int GetID();
    int unk04[9];
    SwTile* unk28;
    int unk2c;
    SwTile* unk30;
    int unk34;
    SwTile* unk38;
    SwTile* unk3c;
    int unk40;
    unsigned char unk44;
    unsigned char m_bSleep;

};

struct SwMenuRoot
{
};
struct SwInterface
{
};
struct SwSoundHandle
{
    int unk00, unk04, unk08;
    ~SwSoundHandle();
};
struct SwAudio
{
    SwSoundHandle FUN_00ad7550(const char* pcName, unsigned int uiFlags, int i);
};

struct SwStrSetting
{
};
struct SwFloatSetting
{
};

static const char s_szMenuPath[] = "Data\\Menus\\sleep_wait_menu.xml";
static const char s_szError[] = "MENUS: Sleep Wait Menu Creation Failed... Are your menu and art resources up to date?";
static const char s_szSound[] = "UIPopUpMessageGeneral";
static const char s_szTitleFormat[] = "%s %s?";
static const char s_szHourFormat[] = "1 %s";
static const char s_szBackground[] = "SWM_Background";
extern const char g_szSleepWaitEnd[] = "";

// Creates the sleep/wait menu from s_szMenuPath, sets its title, verb, hour, clock, and background, and returns the root tile or 0 on failure.
// @fnv 0x007bfc30
SwTile* __cdecl CreateSleepWaitMenu(bool bSleep)
{
    SwInterface* pkInterfaceY = ((::SwInterface *)(::fnv_004b7210::FUN_004b7210()));
    SwMenu* pkOld_ = ((::SwMenu *)(::FUN_00a09030(((int)(::FUN_00705770())))));
    if (pkOld_)
        delete pkOld_;
    SwTile* pkTileTmp2 = ((::SwTile *)(reinterpret_cast<::fnv_00a01b00::TileLoader *>((((::SwMenuRoot *)(reinterpret_cast<::InterfaceManager *>((pkInterfaceY))->FUN_00586150()))))->FUN_00a01b00((void *)(s_szMenuPath))));
    (*reinterpret_cast<::SwMenu * *>(&::DAT_011da920)) = ((::SwMenu *)(reinterpret_cast<::FUN_00a03c90_shell *>((pkTileTmp2))->FUN_00a03c90()));
    if ((*reinterpret_cast<::SwMenu * *>(&::DAT_011da920)) && (*reinterpret_cast<::SwMenu * *>(&::DAT_011da920))->GetID() == ((int)(::FUN_00705770())))
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>(((*reinterpret_cast<::SwMenu * *>(&::DAT_011da920))))->FUN_00a1dc70((::TileMenu *)(pkTileTmp2), 0);
        if (!reinterpret_cast<::FUN_007abdb0_shell *>(((*reinterpret_cast<::SwMenu * *>(&::DAT_011da920))))->FUN_007abdb0())
        {
            ::FUN_005b5e40();
            return 0;
        }
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::SwSoundHandle &)(((::SwAudio *)(::FUN_00453a70()))->FUN_00ad7550(s_szSound, 0x121, 0)))->FUN_00ad8830({});
        if (reinterpret_cast<::TileListBoxCalls *>((pkTileTmp2))->GetFloat(0xfa7) == 6006.0 || reinterpret_cast<::TileListBoxCalls *>((pkTileTmp2))->GetFloat(0xfa7) == 102.0)
            reinterpret_cast<::FUN_00a012d0_t *>((pkTileTmp2))->FUN_00a012d0(0xfad, ::Tile::GetInterfaceScale(), true);
        (*reinterpret_cast<::SwMenu * *>(&::DAT_011da920))->m_bSleep = bSleep;
        char acVerb[0x104];
        if (bSleep)
            ::TaskQueueInterface::CopyStringToBuffer(acVerb, 0x104, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SwStrSetting *>(&::g_011d3948))))->GetMenuTitle())));
        else
            ::TaskQueueInterface::CopyStringToBuffer(acVerb, 0x104, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SwStrSetting *>(&::g_011d23ac))))->GetMenuTitle())));
        char acText[0x104];
        ::FUN_00406d00(acText, 0x104, s_szTitleFormat, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SwStrSetting *>(&::g_011d2910))))->GetMenuTitle())), acVerb);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::SwMenu * *>(&::DAT_011da920))->unk28))->FUN_00a01350(0xfc4, (char *)(acText), true);
        acVerb[0] = toupper(acVerb[0]);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::SwMenu * *>(&::DAT_011da920))->unk38))->FUN_00a01350(0xfc4, (char *)(acVerb), true);
        ::FUN_00406d00(acText, 0x104, s_szHourFormat, ((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SwStrSetting *>(&::g_011d448c))))->GetMenuTitle())));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::SwMenu * *>(&::DAT_011da920))->unk30))->FUN_00a01350(0xfc4, (char *)(acText), true);
        reinterpret_cast<::Menu *>(((*reinterpret_cast<::SwMenu * *>(&::DAT_011da920))))->UpdateClockText();
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::SwMenu * *>(&::DAT_011da920))->unk3c))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SwStrSetting *>(&::g_011d29f4))))->GetMenuTitle()))), true);
        reinterpret_cast<::FUN_00a012d0_t *>((((::SwTile *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((::SwTile *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::SwMenu * *>(&::DAT_011da920))))->FUN_00726070()))))->FUN_00a03da0((char *)(s_szBackground))))))->FUN_00a012d0(0xfa9, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SwFloatSetting *>(&::g_011d3174)))))) * 255.0, true);
        reinterpret_cast<::Menu *>(((*reinterpret_cast<::SwMenu * *>(&::DAT_011da920))))->SetMenuVisibility(0);
        return pkTileTmp2;
    }
    else
    {
        if ((*reinterpret_cast<::SwMenu * *>(&::DAT_011da920)) && ((::SwTile *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::SwMenu * *>(&::DAT_011da920))))->FUN_00726070())))
            delete (*reinterpret_cast<::SwMenu * *>(&::DAT_011da920));
    }
    return 0;
}

struct Menu_007a8b10
{
    virtual ~Menu_007a8b10();
};
extern int DAT_010763ac;
struct FUN_007bfc00_shell : Menu_007a8b10
{
    void FUN_007bfc00();
};
// Sets the vtable pointer to DAT_010763ac, zeroes DAT_011da920, and calls the Menu_007a8b10 destructor.
// @fnv 0x007bfc00
void FUN_007bfc00_shell::FUN_007bfc00()
{
    *reinterpret_cast<int**>(this) = &DAT_010763ac;
    DAT_011da920 = 0;
    reinterpret_cast<::fnv_00a1c520::FUN_00a1c520 *>(this)->fnv_00a1c520::FUN_00a1c520::~FUN_00a1c520();
}

#include "generated/data/fallout/interface/menus/sleepwaitmenu.inc"
