
// fallout/interface/menus/quantitymenu.cpp
//
// Recovered quantity-menu translation unit. Every menu derives from Menu and
// overrides the shared AssignTileByID slot with its own tile table.
#include <cstdint>
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_007abdb0_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/InterfaceManager.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a1d9e0__FUN_00a1d9e0_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00707000.h"
#include "fnv/symbols_007ab000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_01012000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011da000.h"
#include "quantitymenu.h"

// Stores tile into the tile array at index when index is within [0, NUM_TILES).
// @fnv 0x007a8ab0
void SleepWaitMenu::AssignTileByID(int index, Tile* tile)
{
    if (index >= 0 && index < NUM_TILES)
        m_pTiles[index] = tile;
}

namespace fnv_007abdf0 {
struct Tile
{
    void Set(int, int);
};
struct Holder
{
};
// If DAT_011da618 is set, sets its tile to 0x1772/1, then calls FUN_00a1d9e0 or FUN_00a1d910 depending on FUN_00707ad0.
// @fnv 0x007abdf0
void FUN_007abdf0()
{
    if ((*reinterpret_cast<::fnv_007abdf0::Holder * *>(&::fnv_00720a70::DAT_011da618)))
    {
        ((::fnv_007abdf0::Tile *)(reinterpret_cast<::Callees *>(((*reinterpret_cast<::fnv_007abdf0::Holder * *>(&::fnv_00720a70::DAT_011da618))))->FUN_00726070()))->Set(0x1772, 1);
        if (((std::intptr_t)(::FUN_00707ad0())))
            reinterpret_cast<::fnv_00a1d9e0::FUN_00a1d9e0_shell *>(((*reinterpret_cast<::fnv_007abdf0::Holder * *>(&::fnv_00720a70::DAT_011da618))))->FUN_00a1d9e0();
        else
            reinterpret_cast<::FUN_00a1d910_shell *>(((*reinterpret_cast<::fnv_007abdf0::Holder * *>(&::fnv_00720a70::DAT_011da618))))->FUN_00a1d910();
    }
}
}  // namespace fnv_007abdf0

struct QuantityMenu
{
    virtual void Unk00();
    virtual void Unk01();
    virtual void Unk02();
    virtual void Unk03(int, int);
    bool HandleButton(int aiButton, float afValue);
};
// Handles button 0xA by calling Unk03(5, 0) and returns whether the button was handled.
// @fnv 0x007ac130
bool QuantityMenu::HandleButton(int aiButton, float afValue)
{
    bool bhandled = false;
    if (aiButton == 0xA)
    {
        Unk03(5, 0);
        bhandled = true;
    }
    return bhandled;
}

struct MenuValueReader
{
};
struct MenuValueWatcher
{
    void* vtable;
    int unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24;
    MenuValueReader* thresholdSource;
    int unk2c, unk30;
    MenuValueReader* valueSource;
    int unk38, unk3c;
    float lastValue;
    void UpdateThresholdCheck();
};
// @fnv 0x007ac170
void MenuValueWatcher::UpdateThresholdCheck()
{
    if (FUN_00408820(reinterpret_cast<::TileListBoxCalls *>((valueSource))->GetFloat(0xfc4) - lastValue) >= reinterpret_cast<::TileListBoxCalls *>((thresholdSource))->GetFloat(0x1007))
    {
        FUN_00706f30(4);
        lastValue = reinterpret_cast<::TileListBoxCalls *>((valueSource))->GetFloat(0xfc4);
    }
}

struct Tile_7aba00
{
    void FUN_00700320(int id, int value);
};
struct Menu_7aba00
{
    virtual ~Menu_7aba00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual int GetID();
    void* unk04;
    int unk08;
    int unk0c;
    int unk10;
    int unk14;
    int unk18;
    int unk1c;
    int unk20;
    int unk24;
    Tile_7aba00* tile28;
    int unk2c;
    int unk30;
    int unk34;
    Tile_7aba00* tile38;
    Tile_7aba00* tile3c;
};
struct IM_7aba00
{
};
struct Sound_7aba00
{
    int unk00;
    int unk04;
    int unk08;
    ~Sound_7aba00();
};
struct Audio_7aba00
{
    Sound_7aba00 FUN_00ad7550(const char* id, unsigned int flags);
};
struct SettingS_7aba00
{
};
struct SettingF_7aba00
{
};
int FUN_007abda0();
float FUN_00a01530();
static const char kMenuFile_7aba00[] = "Data\\Menus\\quantity_menu.xml";
static const char kWarning_7aba00[] =
    "MENUS: Quantity Menu Creation Failed... Are your menu and art resources up to date?";
static const char kSound_7aba00[] = "UIPopUpMessageWindow";
static const char kChild1_7aba00[] = "QM_HowManyText";
static const char kChild2_7aba00[] = "QM_Background";
// Loads quantity_menu.xml, builds the quantity menu, sets its max/initial/step values and labels, stores the callback, and returns the tile or 0 on failure.
// @fnv 0x007aba00
Tile_7aba00* __cdecl CreateQuantityMenu(intptr_t max, void* callback, int initial)
{
    IM_7aba00* im4 = ((::IM_7aba00 *)(::fnv_004b7210::FUN_004b7210()));
    bool flag_ = false;
    Menu_7aba00* old = ((::Menu_7aba00 *)(::FUN_00a09030(FUN_007abda0())));
    if (old)
        delete old;
    if (::fnv_007023c0::FUN_007023c0())
        flag_ = true;
    Tile_7aba00* tile6 = ((::Tile_7aba00 *)(reinterpret_cast<::fnv_00a01b00::TileLoader *>((((::Tile_7aba00 *)(reinterpret_cast<::InterfaceManager *>((im4))->FUN_00586150()))))->FUN_00a01b00((void *)(kMenuFile_7aba00))));
    (*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618)) = ((::Menu_7aba00 *)(reinterpret_cast<::FUN_00a03c90_shell *>((tile6))->FUN_00a03c90()));
    if ((*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618)) && (*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618))->GetID() == FUN_007abda0())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>(((*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618))))->FUN_00a1dc70((::TileMenu *)(tile6), false);
        if (!reinterpret_cast<::FUN_007abdb0_shell *>(((*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618))))->FUN_007abdb0())
        {
            ::FUN_005b5e40();
            return 0;
        }
        reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::Sound_7aba00 &)(((::Audio_7aba00 *)(::FUN_00453a70()))->FUN_00ad7550(kSound_7aba00, 0x121)))->FUN_00ad8830(false);
        if (reinterpret_cast<::TileListBoxCalls *>((tile6))->GetFloat(0xfa7) == 6006.0 || reinterpret_cast<::TileListBoxCalls *>((tile6))->GetFloat(0xfa7) == 102.0)
        {
            reinterpret_cast<::FUN_00a012d0_t *>((tile6))->FUN_00a012d0(0xfad, FUN_00a01530(), true);
        }
        int value9 = MinInt(initial, max);
        int bigStep = FUN_00647b70(max / 20, 1);
        int smallStep = FUN_00647b70(max / 4, 1);
        if (bigStep > 10)
            bigStep -= bigStep % 10;
        (*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618))->tile28->FUN_00700320(0x1004, max);
        (*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618))->tile28->FUN_00700320(0x1006, value9);
        (*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618))->tile28->FUN_00700320(0x1007, bigStep);
        (*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618))->tile28->FUN_00700320(0x1008, smallStep);
        reinterpret_cast<::FUN_00a012d0_t *>(((*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618))->tile28))->FUN_00a012d0(0xff0, 0.0f, true);
        (*reinterpret_cast<void * *>(&::g_pSleepWaitCallback)) = callback;
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((((::Tile_7aba00 *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((tile6))->FUN_00a03da0((char *)(kChild1_7aba00))))))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingS_7aba00 *>(&::g_011d3ac8))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618))->tile38))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingS_7aba00 *>(&::g_011d38b8))))->GetMenuTitle()))), true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>(((*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618))->tile3c))->FUN_00a01350(0xfc4, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingS_7aba00 *>(&::g_011d29f4))))->GetMenuTitle()))), true);
        if (flag_)
        {
            reinterpret_cast<::FUN_00a012d0_t *>((((::Tile_7aba00 *)(reinterpret_cast<::fnv_00a03da0::FUN_00a03da0_shell *>((((::Tile_7aba00 *)((*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618))->unk04))))->FUN_00a03da0((char *)(kChild2_7aba00))))))->FUN_00a012d0(0xfa9, *((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingF_7aba00 *>(&::g_011d3bc8)))))) * 255.0, true);
        }
        reinterpret_cast<::Menu *>(((*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618))))->SetMenuVisibility(false);
        return tile6;
    }
    else
    {
        if ((*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618)) && ((::Tile_7aba00 *)((*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618))->unk04)))
            delete (*reinterpret_cast<::Menu_7aba00 * *>(&::fnv_00720a70::DAT_011da618));
    }
    return 0;
}

class Tile
{
  public:
};


struct SleepWaitMenuStub : public Menu
{
    Tile* m_pTiles[6];
    void HandleTileInput(int index, Tile* tile);
};

// @fnv 0x007abe40
void SleepWaitMenuStub::HandleTileInput(int index, Tile* tile)
{
    float fValue = reinterpret_cast<::TileListBoxCalls *>((m_pTiles[3]))->GetFloat(0xfc4);
    if (!tile && index >= 0 && index < 6)
        tile = m_pTiles[index];
    switch (index)
    {
    case 4:
    case 5:
        if (g_pSleepWaitCallback)
            g_pSleepWaitCallback(index == 4 ? ::FUN_00406d90(fValue) : 0);
        ::fnv_007abdf0::FUN_007abdf0();
        break;
    case 1:
    case 2: {
        float fScaledValue = reinterpret_cast<::TileListBoxCalls *>((m_pTiles[0]))->GetFloat(0x1004);
        reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[0]))->FUN_00a012d0(
            0x1006, FUN_0040ebd0(FUN_00404010(fValue + (index == 2 ? 1.0f : ::DAT_01012054), 0.0f), fScaledValue), true);
        reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[0]))->FUN_00a012d0(0xff0, 0.0f, true);
    }
    break;
    }
}


struct QtyTile
{
};

struct QtyMenuStub : public Menu
{
    QtyTile* pScrollTile;
    QtyTile* pTile2C;
    QtyTile* pTile30;
    QtyTile* pBarTile;

    bool HandleQuantityKey(int aiKey, int aiUnused);
};

// @fnv 0x007abf80
bool QtyMenuStub::HandleQuantityKey(int aiKey, int aiUnused)
{
    bool bHandled = false;
    switch (aiKey)
    {
    case 13:
    case 14: {
        float fCur4 = reinterpret_cast<::TileListBoxCalls *>((pBarTile))->GetFloat(0xFC4);
        float fScaledValue = reinterpret_cast<::TileListBoxCalls *>((pScrollTile))->GetFloat(0x1004);
        float fStep = reinterpret_cast<::TileListBoxCalls *>((pScrollTile))->GetFloat(0x1008);
        reinterpret_cast<::FUN_00a012d0_t *>((pScrollTile))->FUN_00a012d0(
            0x1006, FUN_0040ebd0(FUN_00404010(fCur4 + (aiKey == 14 ? fStep : -fStep), 0.0f), fScaledValue), true);
        reinterpret_cast<::FUN_00a012d0_t *>((pScrollTile))->FUN_00a012d0(0xFF0, 0.0f, true);
        bHandled = true;
    }
    break;
    case 15:
    case 16: {
        float fCur3 = reinterpret_cast<::TileListBoxCalls *>((pBarTile))->GetFloat(0xFC4);
        float fMax2 = reinterpret_cast<::TileListBoxCalls *>((pScrollTile))->GetFloat(0x1004);
        float fStep9 = reinterpret_cast<::TileListBoxCalls *>((pScrollTile))->GetFloat(0x1007);
        reinterpret_cast<::FUN_00a012d0_t *>((pScrollTile))->FUN_00a012d0(
            0x1006, FUN_0040ebd0(FUN_00404010(fCur3 + (aiKey == 16 ? fStep9 : -fStep9), 0.0f), fMax2), true);
        reinterpret_cast<::FUN_00a012d0_t *>((pScrollTile))->FUN_00a012d0(0xFF0, 0.0f, true);
        bHandled = true;
    }
    break;
    }
    return bHandled;
}

#include "generated/data/fallout/interface/menus/quantitymenu.inc"
