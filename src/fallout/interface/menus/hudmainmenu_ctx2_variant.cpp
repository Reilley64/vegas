
// hudmainmenu_ctx2_variant.cpp: context variant of src/fallout/interface/menus/hudmainmenu.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include <new>
#include "fnv/decl/ActorValueUtility.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_00464e10_shell.h"
#include "fnv/decl/FUN_00953c20_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/HotkeyWheelDisplay.h"
#include "fnv/decl/NiNodeBooleanState.h"
#include "fnv/decl/SoundPlaybackHandle.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Twin_0044ddc0.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0087f9f0__FUN_0087f9f0_shell.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a07c60__FUN_00a07c60_shell.h"
#include "fnv/decl/fnv_00a07dc0__FUN_00a07dc0_shell.h"
#include "fnv/decl/fnv_00a07f30__FUN_00a07f30_shell.h"
#include "fnv/decl/fnv_00a07fc0__FUN_00a07fc0_shell.h"
#include "fnv/symbols_00404000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_0040e000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_004a8000.h"
#include "fnv/symbols_004b3000.h"
#include "fnv/symbols_005c7000.h"
#include "fnv/symbols_00647000.h"
#include "fnv/symbols_00702000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_011a0000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f2000.h"
#include "fnv/symbols_011f6000.h"
#include "HUDMainMenu.h"
static const int kGetClassValue = 1004;
// m_pTiles is addressed by 1-based tile ID; slot 0 is the menu root.
enum
{
    kTileIDMax = 86
};

class Tile
{
  public:
    void Set(int, int);
public:
    void Set(int, unsigned int);
};
struct XPState
{
};
struct XPValues
{
    virtual void Slot0();
    virtual void Slot1();
    virtual void Slot2();
    virtual float GetValue(int);
};
struct XPPlayer
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
    int unk34;
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
    int unk94;
    int unk98;
    int unk9c;
    int unka0;
    XPValues values;
};
struct XPVats
{
};
struct XPGate
{
};
struct AmountEntry
{
    int unk00;
    int unk04;
    int amount;
};
struct XPSetting
{
};
struct XPClock
{
};
struct XPSound
{
    int soundID;
    int state;
    int unk08;
    XPSound();
    ~XPSound();
    XPSound& operator=(const XPSound&);
};
struct XPAudio
{
    XPSound GetSoundByEditorID(const char*, unsigned int);
};
extern int xpCurrentLevel, xpNextLevel;
struct XPMenu : HUDMainMenu
{
    void FUN_0077c4e0();
};

// @fnv 0x0077c4e0
void XPMenu::FUN_0077c4e0()
{
    static int minTrait = ::FUN_00a00940("_x_min", -1);
    static int maxTrait = ::FUN_00a00940("_x_max", -1);
    bool hasPendingLevel18 = ((int)(reinterpret_cast<::FUN_00953c20_shell *>(((*reinterpret_cast<::XPPlayer * *>(&::_g_thePlayer))))->FUN_00953c20())) > 0;
    bool canLevelUp13 = reinterpret_cast<::NiNodeBooleanState *>((((::XPState *)(reinterpret_cast<::FUN_00464e10_shell *>(((*reinterpret_cast<::XPPlayer * *>(&::_g_thePlayer))))->FUN_00464e10()))))->GetBooleanValue();
    if ((FUN_00702360() && ::fnv_007023c0::FUN_007023c0() != 1008 && ::fnv_007023c0::FUN_007023c0() != 1055 && ::fnv_007023c0::FUN_007023c0() != 1057 &&
         ::fnv_007023c0::FUN_007023c0() != 1009) ||
        ((unsigned int)(reinterpret_cast<::Twin_0044ddc0 *>(&((*reinterpret_cast<::XPVats *>(&::g_011f2250))))->GetName())) == 4 || reinterpret_cast<::HotkeyWheelDisplay *>((((XPGate*)m_kMenuData)))->GetVisible())
    {
        ::g_pHudMainMenuInstance->m_pTiles[44]->Set(4003, 0);
        ::g_pHudMainMenuInstance->m_pTiles[45]->Set(4003, 0);
        ::g_pHudMainMenuInstance->m_pTiles[46]->Set(4003, 0);
        ::g_pHudMainMenuInstance->m_pTiles[47]->Set(4003, 0);
        ::g_pHudMainMenuInstance->m_pTiles[48]->Set(4003, 0);
        ::g_pHudMainMenuInstance->m_pTiles[49]->Set(4003, 0);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[44]))->FUN_00a012d0(4009, 0.0f, true);
        reinterpret_cast<::fnv_00a07dc0::FUN_00a07dc0_shell *>((::g_pHudMainMenuInstance->m_pTiles[44]))->RemoveFadeItemsForTile(4009);
        (*reinterpret_cast<unsigned int *>(&::fnv_00773050::DAT_011a010c)) |= 1;
        m_bSequenceActive = false;
    }
    else if (::DAT_011d979c == 0.0)
    {
        m_bSequenceActive = true;
    }
    else
    {
        float alpha = reinterpret_cast<::TileListBoxCalls *>((m_pTiles[44]))->GetFloat(4009);
        bool visible = alpha > 0.0;
        bool done = reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((m_pTiles[44]))->FUN_00a07fc0(4009);
        if ((*reinterpret_cast<unsigned int *>(&::fnv_00773050::DAT_011a010c)) & 1)
        {
            if (!visible && done && !((BSSimpleList<AmountEntry*>*)m_kXPUpdates)->IsEmpty())
            {
                BSSimpleList<AmountEntry*>* node = (BSSimpleList<AmountEntry*>*)m_kXPUpdates;
                int total = 0;
                while (node && !node->IsEmpty())
                {
                    total += ((::AmountEntry *)(new ((void *)(node)) ::Vec3()))->amount;
                    node = ((::BSSimpleList< ::AmountEntry *> *)(reinterpret_cast<::Callees *>((node))->FUN_00726070()));
                }
                while (((::AmountEntry *)(new ((void *)(((BSSimpleList<AmountEntry*>*)m_kXPUpdates))) ::Vec3())))
                {
                    AmountEntry* update = ((::AmountEntry *)(new ((void *)(((BSSimpleList<AmountEntry*>*)m_kXPUpdates))) ::Vec3()));
                    delete update;
                    ((BSSimpleList<AmountEntry*>*)m_kXPUpdates)->RemoveHead();
                }
                if (total > 0 && !m_bSequenceActive)
                {
                    float position;
                    {
                        XPSound xpSound12;
                        reinterpret_cast<::SoundPlaybackHandle *>((void *)&(const ::XPSound &)(xpSound12))->operator=((const ::SoundPlaybackHandle &)((const ::XPSound &)(((::XPAudio *)(::FUN_00453a70()))->GetSoundByEditorID("UIPopUpExperienceUp", 0x121))));
                        reinterpret_cast<::FUN_00ad8830_shell *>(&(xpSound12))->FUN_00ad8830(false);
                        position = 0.0f;
                        int levelStartXP28 = 0;
                        int levelEndXP11 = 0;
                        int currentXP15 = (int)(*reinterpret_cast<::XPPlayer * *>(&::_g_thePlayer))->values.GetValue(24);
                        xpCurrentLevel = reinterpret_cast<::fnv_0087f9f0::FUN_0087f9f0_shell *>(((*reinterpret_cast<::XPPlayer * *>(&::_g_thePlayer))))->FUN_0087f9f0();
                        xpNextLevel = xpCurrentLevel + 1;
                        levelStartXP28 = ::ActorValueUtility::ConvertActorValue(xpCurrentLevel);
                        levelEndXP11 = ::ActorValueUtility::ConvertActorValue(xpNextLevel);
                        if (currentXP15 > levelEndXP11 && hasPendingLevel18)
                            position = reinterpret_cast<::TileListBoxCalls *>((m_pTiles[47]))->GetFloat(maxTrait);
                        if (levelStartXP28 == levelEndXP11)
                            position = (float)levelStartXP28;
                        else
                            position = LinearInterpolate(reinterpret_cast<::TileListBoxCalls *>((m_pTiles[47]))->GetFloat(minTrait), reinterpret_cast<::TileListBoxCalls *>((m_pTiles[47]))->GetFloat(maxTrait),
                                                         (float)levelStartXP28, (float)levelEndXP11,
                                                         (*reinterpret_cast<::XPPlayer * *>(&::_g_thePlayer))->values.GetValue(24) - total);
                        reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[47]))->FUN_00a012d0(4001,
                                          ::FUN_0040ebd0(::FUN_00404010(position, reinterpret_cast<::TileListBoxCalls *>((m_pTiles[47]))->GetFloat(minTrait)),
                                                      reinterpret_cast<::TileListBoxCalls *>((m_pTiles[47]))->GetFloat(maxTrait)),
                                          true);
                        m_pTiles[44]->Set(4003, 1);
                        m_pTiles[45]->Set(4003, 1);
                        m_pTiles[46]->Set(4003, 1);
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[46]))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::XPSetting *>(&::g_011d3bd4))))->GetMenuTitle()))), true);
                        m_pTiles[47]->Set(4003, 1);
                        m_pTiles[48]->Set(4003, 1);
                        m_pTiles[49]->Set(4003, 1);
                        reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[44]))->FUN_00a012d0(4009, 0.0f, true);
                        reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[45]))->FUN_00a012d0(4009, 0.0f, true);
                        reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[46]))->FUN_00a012d0(4009, 0.0f, true);
                        reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[47]))->FUN_00a012d0(4009, 0.0f, true);
                        reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[48]))->FUN_00a012d0(4009, 0.0f, true);
                        reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[49]))->FUN_00a012d0(4009, 0.0f, true);
                        char text[16];
                        ::FUN_00406d00(text, 16, "+%i", total);
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[45]))->FUN_00a01350(4036, (char *)(text), true);
                        ::FUN_00406d00(text, 16, "%i", xpCurrentLevel);
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[48]))->FUN_00a01350(4036, (char *)(text), true);
                        ::FUN_00406d00(text, 16, "%i", xpNextLevel);
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[49]))->FUN_00a01350(4036, (char *)(text), true);
                        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[44]))->StartFade(4009, 0.0f, ::DAT_011d979c, 2.0f, 0);
                        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[45]))->StartFade(4009, 0.0f, ::DAT_011d979c, 2.0f, 0);
                        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[46]))->StartFade(4009, 0.0f, ::DAT_011d979c, 2.0f, 0);
                        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[47]))->StartFade(4009, 0.0f, ::DAT_011d979c, 2.0f, 0);
                        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[48]))->StartFade(4009, 0.0f, ::DAT_011d979c, 2.0f, 0);
                        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[49]))->StartFade(4009, 0.0f, ::DAT_011d979c, 2.0f, 0);
                        visible = true;
                    }
                }
            }
            else
            {
                float animatedPosition1 = reinterpret_cast<::fnv_00a07f30::FUN_00a07f30_shell *>((m_pTiles[47]))->GetTraitFloat(4001);
                float meterMin34 = reinterpret_cast<::TileListBoxCalls *>((m_pTiles[47]))->GetFloat(minTrait);
                float meterMax4 = reinterpret_cast<::TileListBoxCalls *>((m_pTiles[47]))->GetFloat(maxTrait);
                bool meterDone = reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((m_pTiles[47]))->FUN_00a07fc0(4001);
                if (!reinterpret_cast<::FUN_00a01230_shell *>((m_pTiles[47]))->IsTraitNonZero(4111) && done && visible)
                {
                    int currentXP15 = (int)(*reinterpret_cast<::XPPlayer * *>(&::_g_thePlayer))->values.GetValue(24);
                    if (xpCurrentLevel == xpNextLevel)
                        ++xpNextLevel;
                    int levelStartXP8 = ::ActorValueUtility::ConvertActorValue(xpCurrentLevel);
                    int levelEndXP11 = ::ActorValueUtility::ConvertActorValue(xpNextLevel);
                    m_pTiles[47]->Set(4111, 1);
                    if (currentXP15 > levelEndXP11)
                    {
                        if (meterMax4 < reinterpret_cast<::TileListBoxCalls *>((m_pTiles[47]))->GetFloat(4001))
                            reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[47]))->FUN_00a012d0(4001, meterMax4, true);
                        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[47]))->StartFade(4001, reinterpret_cast<::TileListBoxCalls *>((m_pTiles[47]))->GetFloat(4001), meterMax4, 1.0f, 0);
                    }
                    else
                    {
                        reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[47]))->StartFade(
                            4001, reinterpret_cast<::TileListBoxCalls *>((m_pTiles[47]))->GetFloat(4001),
                            LinearInterpolate(meterMin34, meterMax4, (float)levelStartXP8, (float)levelEndXP11,
                                              (float)::MinInt(::FUN_00647b70(currentXP15, levelStartXP8), levelEndXP11)),
                            2.0f, 0);
                    }
                }
                else if (done && !visible)
                {
                    ::g_pHudMainMenuInstance->m_pTiles[44]->Set(4003, 0);
                    ::g_pHudMainMenuInstance->m_pTiles[45]->Set(4003, 0);
                    ::g_pHudMainMenuInstance->m_pTiles[46]->Set(4003, 0);
                    ::g_pHudMainMenuInstance->m_pTiles[47]->Set(4003, 0);
                    ::g_pHudMainMenuInstance->m_pTiles[48]->Set(4003, 0);
                    ::g_pHudMainMenuInstance->m_pTiles[49]->Set(4003, 0);
                    if (((*reinterpret_cast<unsigned int *>(&::fnv_00773050::DAT_011a010c)) & 8) && !m_bSequenceActive)
                    {
                        m_bSequenceActive = true;
                        m_pTiles[50]->Set(4110, 0);
                    }
                }
                else if (!meterDone && done && visible)
                {
                    int currentXP15 = (int)(*reinterpret_cast<::XPPlayer * *>(&::_g_thePlayer))->values.GetValue(24);
                    int levelStartXP8 = ::ActorValueUtility::ConvertActorValue(xpCurrentLevel);
                    int levelEndXP11 = ::ActorValueUtility::ConvertActorValue(xpNextLevel);
                    if (canLevelUp13 && meterMax4 == reinterpret_cast<::TileListBoxCalls *>((m_pTiles[47]))->GetFloat(4001) && !::FUN_005c7870((const char *)((*reinterpret_cast<::XPPlayer * *>(&::_g_thePlayer)))) &&
                        !hasPendingLevel18)
                        ::s717280::FUN_00717280(21);
                    if (currentXP15 > levelEndXP11 && xpNextLevel < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::XPSetting *>(&::g_011d0c60)))))) && !hasPendingLevel18)
                    {
                        ++xpCurrentLevel;
                        ++xpNextLevel;
                        levelStartXP8 = levelEndXP11;
                        levelEndXP11 = ::ActorValueUtility::ConvertActorValue(xpNextLevel);
                        reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[47]))->FUN_00a012d0(4001, meterMin34, true);
                        char levelText[3];
                        ::FUN_00406d00(levelText, 3, "%i", xpCurrentLevel);
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[48]))->FUN_00a01350(4036, (char *)(levelText), true);
                        ::FUN_00406d00(levelText, 3, "%i", xpNextLevel);
                        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[49]))->FUN_00a01350(4036, (char *)(levelText), true);
                        if (currentXP15 > levelEndXP11)
                        {
                            if (meterMin34 > meterMax4)
                                meterMin34 = meterMax4;
                            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[47]))->StartFade(4001, meterMin34, meterMax4, 1.0f, 0);
                        }
                        else
                        {
                            reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[47]))->StartFade(4001, meterMin34,
                                                  LinearInterpolate(meterMin34, meterMax4, (float)levelStartXP8,
                                                                    (float)levelEndXP11, (float)currentXP15),
                                                  2.0f, 0);
                        }
                    }
                }
                else if (reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((m_pTiles[47]))->FUN_00a07fc0(4001) && reinterpret_cast<::FUN_00a01230_shell *>((m_pTiles[47]))->IsTraitNonZero(4111) && reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((m_pTiles[44]))->FUN_00a07fc0(4009) &&
                         reinterpret_cast<::TileListBoxCalls *>((m_pTiles[44]))->GetFloat(4009) > 0.0)
                {
                    m_pTiles[47]->Set(4111, 0);
                    reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[44]))->StartFade(4009, reinterpret_cast<::TileListBoxCalls *>((m_pTiles[44]))->GetFloat(4009), 0.0f, 2.0f, 0);
                    reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[45]))->StartFade(4009, reinterpret_cast<::TileListBoxCalls *>((m_pTiles[45]))->GetFloat(4009), 0.0f, 2.0f, 0);
                    reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[46]))->StartFade(4009, reinterpret_cast<::TileListBoxCalls *>((m_pTiles[46]))->GetFloat(4009), 0.0f, 2.0f, 0);
                    reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[47]))->StartFade(4009, reinterpret_cast<::TileListBoxCalls *>((m_pTiles[47]))->GetFloat(4009), 0.0f, 2.0f, 0);
                    reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[48]))->StartFade(4009, reinterpret_cast<::TileListBoxCalls *>((m_pTiles[48]))->GetFloat(4009), 0.0f, 2.0f, 0);
                    reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[49]))->StartFade(4009, reinterpret_cast<::TileListBoxCalls *>((m_pTiles[49]))->GetFloat(4009), 0.0f, 2.0f, 0);
                }
            }
            if (canLevelUp13)
            {
                if (!hasPendingLevel18 && !visible && !((*reinterpret_cast<unsigned int *>(&::fnv_00773050::DAT_011a010c)) & 8))
                    (*reinterpret_cast<unsigned int *>(&::fnv_00773050::DAT_011a010c)) = 2;
                else
                    (*reinterpret_cast<unsigned int *>(&::fnv_00773050::DAT_011a010c)) |= 4;
            }
        }
        else if (((*reinterpret_cast<unsigned int *>(&::fnv_00773050::DAT_011a010c)) & 2) && !((*reinterpret_cast<unsigned int *>(&::fnv_00773050::DAT_011a010c)) & 8) && !visible && done && !::FUN_005c7870((const char *)((*reinterpret_cast<::XPPlayer * *>(&::_g_thePlayer)))))
        {
            bool noticeDone = reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((m_pTiles[50]))->FUN_00a07fc0(4009);
            bool noticeZero = reinterpret_cast<::TileListBoxCalls *>((m_pTiles[50]))->GetFloat(4009) == 0.0;
            if (noticeDone && noticeZero && !reinterpret_cast<::FUN_00a01230_shell *>((m_pTiles[50]))->IsTraitNonZero(4110) && ((int)(reinterpret_cast<::FUN_00953c20_shell *>(((*reinterpret_cast<::XPPlayer * *>(&::_g_thePlayer))))->FUN_00953c20())) == 0)
            {
                reinterpret_cast<::FUN_00ad8830_shell *>((void *)&(const ::XPSound &)(((::XPAudio *)(::FUN_00453a70()))->GetSoundByEditorID("UILevelUpText", 0x121)))->FUN_00ad8830(false);
                reinterpret_cast<::FUN_00a012d0_t *>((m_pTiles[50]))->FUN_00a012d0(4009, 0.0f, true);
                reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[50]))->StartFade(4009, 0.0f, ::DAT_011d979c, 0.5f, 0);
                reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((m_pTiles[50]))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::XPSetting *>(&::g_011d4324))))->GetMenuTitle()))), true);
                m_pTiles[50]->Set(4003, 1);
                m_pTiles[50]->Set(4109, reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::XPClock *>(&::g_timeGlobal))))->FUN_00825c00());
                m_pTiles[50]->Set(4110, 1);
            }
            else
            {
                if (reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::XPClock *>(&::g_timeGlobal))))->FUN_00825c00() - reinterpret_cast<::TileListBoxCalls *>((m_pTiles[50]))->GetFloat(4109) > 1500.0 && !noticeZero && noticeDone)
                {
                    m_pTiles[50]->Set(4109, reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&((*reinterpret_cast<::XPClock *>(&::g_timeGlobal))))->FUN_00825c00() + 2000);
                    reinterpret_cast<::fnv_00a07c60::FUN_00a07c60_shell *>((m_pTiles[50]))->StartFade(4009, ::DAT_011d979c, 0.0f, 0.5f, 0);
                }
                else if (!m_bSequenceActive && noticeDone && noticeZero)
                {
                    m_bSequenceActive = true;
                    (*reinterpret_cast<unsigned int *>(&::fnv_00773050::DAT_011a010c)) = 8;
                    m_pTiles[50]->Set(4110, 0);
                }
            }
        }
        else if ((*reinterpret_cast<unsigned int *>(&::fnv_00773050::DAT_011a010c)) & 4)
        {
            bool noticeFinished40 = ((*reinterpret_cast<unsigned int *>(&::fnv_00773050::DAT_011a010c)) & 8) > 0;
            bool noticeDone = reinterpret_cast<::fnv_00a07fc0::FUN_00a07fc0_shell *>((m_pTiles[50]))->FUN_00a07fc0(4009);
            bool noticeIsZero37 = reinterpret_cast<::TileListBoxCalls *>((m_pTiles[50]))->GetFloat(4009) == 0.0;
            if (!noticeFinished40)
            {
                if (hasPendingLevel18)
                    (*reinterpret_cast<unsigned int *>(&::fnv_00773050::DAT_011a010c)) |= 1;
                else if (!visible)
                    (*reinterpret_cast<unsigned int *>(&::fnv_00773050::DAT_011a010c)) = 2;
            }
            else if (!m_bSequenceActive && noticeDone && noticeIsZero37)
            {
                m_bSequenceActive = true;
                (*reinterpret_cast<unsigned int *>(&::fnv_00773050::DAT_011a010c)) = 8;
                m_pTiles[50]->Set(4110, 0);
            }
        }
    }
}

#include "generated/data/fallout/interface/menus/hudmainmenu_ctx2_variant.inc"
