
// hudmainmenu_ctx_variant.cpp: context variant of src/fallout/interface/menus/hudmainmenu.cpp: its stripped skeleton, as these functions were checked
// against, for verified matches whose own declarations clash with the unit's current types.
#include <cstring>
#include "fnv/decl/ActorTaskManager.h"
#include "fnv/decl/BSShaderRenderUtility.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/CamBuilder.h"
#include "fnv/decl/FUN_00438690.h"
#include "fnv/decl/FUN_0043d450_Owner.h"
#include "fnv/decl/FUN_0043fa80_s.h"
#include "fnv/decl/FUN_00440490_shell.h"
#include "fnv/decl/FUN_0045dfc0_shell.h"
#include "fnv/decl/FUN_004a0c90_shell.h"
#include "fnv/decl/FUN_004bc1f0_S.h"
#include "fnv/decl/FUN_00524ac0_shell.h"
#include "fnv/decl/FUN_00770070_Class.h"
#include "fnv/decl/FUN_007700d0_cls.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/FUN_00a59c60_cls.h"
#include "fnv/decl/FontManager.h"
#include "fnv/decl/GlobalObject_0044fae0.h"
#include "fnv/decl/HotkeyWheelDisplay.h"
#include "fnv/decl/MyHost.h"
#include "fnv/decl/NiAVObject.h"
#include "fnv/decl/NiAdditionalGeometryData.h"
#include "fnv/decl/NiControllerManager.h"
#include "fnv/decl/SSN_b5.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/TaskQueueInterface.h"
#include "fnv/decl/TileListBoxCalls.h"
#include "fnv/decl/Twin_0084d030.h"
#include "fnv/decl/fnv_0047a520__Fn47a520.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a1ddb0__FUN_00a1ddb0_shell.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00450000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00713000.h"
#include "fnv/symbols_00715000.h"
#include "fnv/symbols_00717000.h"
#include "fnv/symbols_00771000.h"
#include "fnv/symbols_00774000.h"
#include "fnv/symbols_0077e000.h"
#include "fnv/symbols_008c1000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a04000.h"
#include "fnv/symbols_00a08000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00ad8000.h"
#include "fnv/symbols_011a9000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011d9000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f3000.h"
#include "HUDMainMenu.h"
static const int kGetClassValue = 1004;
// m_pTiles is addressed by 1-based tile ID; slot 0 is the menu root.
enum
{
    kTileIDMax = 86
};

class NiNode;
class NiAVObject;
class NiTimeController;
class NiRTTI;
class NiSourceTexture;
class NiControllerSequence;
class ShadowSceneNode;
struct NiPoint3Stub
{
    float x;
    float y;
    float z;
};
class NiSourceTexture;
class CompassStub
{
  public:
    void FUN_007700b0(NiSourceTexture* texture);
};
class MenuStub;
class Tile
{
  public:
    virtual ~Tile();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual CompassStub* vf20();
public:
    void Set(int, int);
public:
    static float GetInterfaceScale();
};
class TileMenu : public Tile
{
};
class MenuStub
{
  public:
    virtual ~MenuStub();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual unsigned int vf34();
};
class HotKeyWheelStub
{
  public:
};
class InterfaceManager
{
  public:
    Tile* FUN_00586150();
public:
    static float UpdateInterfaceState();
};
class ATMStub
{
  public:
};
class FontManagerStub
{
  public:
    NiPoint3Stub FUN_00a1b020(const char* text, int font, float width, int flags);
};
class SettingString
{
  public:
};
class SettingInt
{
  public:
};
class SettingFloat
{
  public:
};
class NiFixedString
{
  public:
    const char* m_kHandle;
    NiFixedString(const char* text);
    ~NiFixedString();
};
class NiTextureFormatPrefs;
class NiFixedString;
class NiTexture__FormatPrefs;
class NiSourceTexture
{
  public:
    void IncRefCount();
    void DecRefCount();
public:
    static ::NiSourceTexture *Create(const ::NiFixedString &, ::NiTexture__FormatPrefs &, bool, bool);
};
class ThreeByThreeMatrix
{
  public:
    float m00, m01, m02, m10, m11, m12, m20, m21, m22;
    ThreeByThreeMatrix();
public:
    ::ThreeByThreeMatrix operator+(const ::ThreeByThreeMatrix &) const;
};
class NiUpdateData
{
  public:
    float fTime;
    bool m_bUpdateEnabled;
    bool bIsMultiThreaded;
    bool bUnk06;
    bool bUnk07;
    int unk08;
    NiUpdateData(float time, bool updateControllers, bool multiThreaded);
};
class NiBoundStub
{
  public:
};
class NiAVObject;
class NiNode
{
  public:
    unsigned int unk00, unk04, unk08, unk0c, unk10, unk14, unk18, unk1c, unk20, unk24, unk28;
    unsigned int unk2c, unk30, unk34, unk38, unk3c, unk40, unk44, unk48, unk4c, unk50, unk54;
    unsigned int unk58, unk5c, unk60, unk64, unk68, unk6c, unk70, unk74, unk78, unk7c, unk80;
    unsigned int unk84, unk88, unk8c, unk90, unk94, unk98, unk9c, unka0, unka4, unka8;
    static void* operator new(unsigned int size);
    static void operator delete(void*, unsigned int);
    NiNode(unsigned short childCount);
    void IncRefCount();
    void DecRefCount();
public:
    ::NiAVObject *GetAt(unsigned int);
};
class NiControllerManagerStub
{
  public:
};
class ShadowSceneNode
{
  public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0c();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1c();
    virtual void vf20();
    virtual void vf24();
    virtual void vf28();
    virtual void vf2c();
    virtual void vf30();
    virtual void vf34();
    virtual void vf38();
    virtual void vf3c();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4c();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5c();
    virtual void vf60();
    virtual void vf64();
    virtual void vf68();
    virtual void vf6c();
    virtual void vf70();
    virtual void vf74();
    virtual void vf78();
    virtual void vf7c();
    virtual void vf80();
    virtual void vf84();
    virtual void vf88();
    virtual void vf8c();
    virtual void vf90();
    virtual void vf94();
    virtual void vf98();
    virtual void vf9c();
    virtual void vfa0();
    virtual void vfa4();
    virtual void vfa8();
    virtual void vfac();
    virtual void vfb0();
    virtual void vfb4();
    virtual void vfb8();
    virtual void vfbc();
    virtual void vfc0();
    virtual void vfc4();
    virtual void vfc8();
    virtual void vfcc();
    virtual void vfd0();
    virtual void vfd4();
    virtual void vfd8();
    virtual void vfdc(NiNode* node, bool flag);
};
struct HUDEmptyStub
{
};
static const char kTemplateRightBracket[] = "template_right_bracket";
static const char kTemplateMeter3[] = "template_meter";
static const char kTemplateJustifyRightText6[] = "template_justify_right_text";
static const char kTemplateJustifyRightText5[] = "template_justify_right_text";
static const char kTemplateJustifyRightText4[] = "template_justify_right_text";
static const char kTemplateMeter2[] = "template_meter";
static const char kInterfaceVATSVatsBarDds[] = "Interface\\VATS\\vats_bar.dds";
static const char kTemplateMeterBackground[] = "template_meter_background";
static const char kCNDArrows[] = "CNDArrows";
static const char kHitPoints[] = "HitPoints";
static const char kTemplateLeftBracket[] = "template_left_bracket";
static const char kTemplateMeter[] = "template_meter";
static const char kTemplateJustifyRightText3[] = "template_justify_right_text";
static const char kTemplateCompassWindow[] = "template_compass_window";
static const char kTemplateCompassIconGroup[] = "template_compass_icon_group";
static const char kTemplateCompassIconMarker[] = "template_compass_icon_marker";
static const char kRadiationMeter[] = "RadiationMeter";
static const char kTestHeight2[] = "Test Height";
static const char kTemplateJustifyLeftText3[] = "template_justify_left_text";
static const char kTemplateReticleCenter[] = "template_reticle_center";
static const char kSneakMeter[] = "SneakMeter";
static const char kSneakNif[] = "sneak_nif";
static const char kMessages[] = "Messages";
static const char kTemplateMessageIcon[] = "template_message_icon";
static const char kTemplateJustifyLeftText2[] = "template_justify_left_text";
static const char kTemplateMessageBracket[] = "template_message_bracket";
static const char kJustifyCenterHotrect[] = "justify_center_hotrect";
static const char kPCShortcutLabel[] = "PCShortcutLabel";
static const char kXboxButton[] = "xbox_button";
static const char kTestHeight[] = "Test Height";
static const char kTemplateJustifyCenterText3[] = "template_justify_center_text";
static const char kTemplateJustifyCenterText2[] = "template_justify_center_text";
static const char kTemplateJustifyRightText2[] = "template_justify_right_text";
static const char kTemplateJustifyLeftText[] = "template_justify_left_text";
static const char kTemplateJustifyRightText[] = "template_justify_right_text";
static const char kTemplateJustifyCenterText[] = "template_justify_center_text";
static const char kHokeys[] = "Hokeys";
// @fnv 0x0076bfe0
Tile* FUN_0076bfe0()
{
    InterfaceManager* pInterfaceMgrY;
    MenuStub* pMenuXB;
    float fTileAlphaM;
    Tile* pMenuTileN;
    TileMenu* pOldMenuT;

    if (!((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210())))
        return 0;
    pOldMenuT = ((::TileMenu *)(::FUN_00a09030(FUN_00706f20())));
    if (pOldMenuT)
        delete pOldMenuT;
    pInterfaceMgrY = ((::InterfaceManager *)(::fnv_004b7210::FUN_004b7210()));
    fTileAlphaM = ::Tile::GetInterfaceScale();
    reinterpret_cast<::GlobalObject_0044fae0 *>((((::ATMStub *)(::FUN_00713d70()))))->FUN_004538a0(0);
    pMenuTileN = reinterpret_cast<::fnv_00a01b00::TileLoader *>((pInterfaceMgrY->FUN_00586150()))->FUN_00a01b00((void *)("Data\\Menus\\Main\\hud_main_menu.xml"));
    pMenuXB = ((::MenuStub *)(reinterpret_cast<::FUN_00a03c90_shell *>((pMenuTileN))->FUN_00a03c90()));
    if (pMenuXB && pMenuXB->vf34() == FUN_00706f20())
    {
        reinterpret_cast<::FUN_00a1dc70_shell *>((pMenuXB))->FUN_00a1dc70((::TileMenu *)(pMenuTileN), false);
        int iInfoRowY;
        int iTotalWidthTraitA;
        int iInfoGapLeftAA;
        NiNode* pBreathNodeYA;
        int iOriginalXTrait14;
        float fLimbScaleAC;
        int iSafeZoneX3;
        int iInfoPadLeft_;
        float fShadowRadiusXB;
        Tile* pPlayerIcon;
        int iScreenHeightX;
        int iImageWidthTraitT;
        int iInfoPadMid34;
        NiTimeController* pController27;
        int iScreenWidthC;
        int iSafeZoneYY;
        int iQuestYAA;
        int iMessageOffsetX3;
        int iLimbOffsetXQ;
        int iLimbOffsetYB;
        int iInfoPadRightQ;
        ::g_pHudMainMenuInstance = (HUDMainMenu*)pMenuXB;
        iScreenWidthC = (int)::InterfaceManager::UpdateInterfaceState();
        iScreenHeightX = (int)FUN_00715da0();
        iSafeZoneX3 = (int)FUN_007177c0();
        iSafeZoneYY = (int)::fnv_00717820::FUN_00717820();
        iOriginalXTrait14 = FUN_00a00940("_OriginalX", -1);
        iTotalWidthTraitA = FUN_00a00940("_TotalWidth", -1);
        iImageWidthTraitT = FUN_00a00940("_ImageWidth", -1);
        ::g_pHudMainMenuInstance->m_pTiles[59] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "ActionPoints")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[59]))->FUN_00a012d0(
            4001, (float)(iScreenWidthC - iSafeZoneX3 * 2) - reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[59]))->GetFloat(4017) + 30.0,
            1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[59]))->FUN_00a012d0(
            4002, (float)(iScreenHeightX - iSafeZoneYY * 2) - reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[59]))->GetFloat(4016), 1);
        ::g_pHudMainMenuInstance->m_pTiles[59]->Set(4008, 1);
        ::g_pHudMainMenuInstance->m_pTiles[43] = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[59], (char *)(kTemplateRightBracket), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[43]), 2);
        ::g_pHudMainMenuInstance->m_pTiles[43]->Set(4001, -37);
        ::g_pHudMainMenuInstance->m_pTiles[7] = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[59], (char *)(kTemplateMeter3), (::Tile *)(0));
        ::g_pHudMainMenuInstance->m_pTiles[7]->Set(iOriginalXTrait14, 326);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[7]))->FUN_00a012d0(4002, 41.0f, 1);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[7]), 3);
        ::g_pHudMainMenuInstance->m_pTiles[8] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[59], (char *)(kTemplateJustifyRightText6), (::Tile *)(0));
        ::g_pHudMainMenuInstance->m_pTiles[8]->Set(4001, 315);
        ::g_pHudMainMenuInstance->m_pTiles[8]->Set(4002, 8);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[8]), 0);
        ::g_pHudMainMenuInstance->m_pTiles[12] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[59], (char *)(kTemplateJustifyRightText5), (::Tile *)(0));
        ::g_pHudMainMenuInstance->m_pTiles[12]->Set(4001, 315);
        ::g_pHudMainMenuInstance->m_pTiles[12]->Set(4002, 80);
        ::g_pHudMainMenuInstance->m_pTiles[12]->Set(4025, 7);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[12]), 0);
        ::g_pHudMainMenuInstance->m_pTiles[9] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[59], (char *)(kTemplateJustifyRightText4), (::Tile *)(0));
        ::g_pHudMainMenuInstance->m_pTiles[9]->Set(4001, 80);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[9]))->FUN_00a012d0(4002, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[12]))->GetFloat(4002), 1);
        ::g_pHudMainMenuInstance->m_pTiles[9]->Set(4025, 7);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((::g_pHudMainMenuInstance->m_pTiles[9]))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingString *>(&::g_011d4da4))))->GetMenuTitle()))), 1);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[9]), 0);
        ::g_pHudMainMenuInstance->m_pTiles[10] = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[59], (char *)(kTemplateMeter2), (::Tile *)(0));
        ::g_pHudMainMenuInstance->m_pTiles[10]->Set(iOriginalXTrait14, 90);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[10]))->FUN_00a012d0(4002, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[12]))->GetFloat(4002) + 3.0, 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((::g_pHudMainMenuInstance->m_pTiles[10]))->FUN_00a01350(4044, (char *)(kInterfaceVATSVatsBarDds), 1);
        ::g_pHudMainMenuInstance->m_pTiles[10]->Set(iTotalWidthTraitA, 60);
        ::g_pHudMainMenuInstance->m_pTiles[10]->Set(iImageWidthTraitT, 1);
        ::g_pHudMainMenuInstance->m_pTiles[10]->Set(4024, 200);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[10]), 3);
        ::g_pHudMainMenuInstance->m_pTiles[11] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[59], (char *)(kTemplateMeterBackground), (::Tile *)(0));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[11]))->FUN_00a012d0(4002, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[12]))->GetFloat(4002) + 3.0, 1);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[11]), 4);
        ::g_pHudMainMenuInstance->m_pTiles[86] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), kCNDArrows)));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[86]))->FUN_00a012d0(4001,
                                                    reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[59]))->GetFloat(4001) +
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[9]))->GetFloat(4001) +
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[10]))->GetFloat(4001) +
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[11]))->GetFloat(4017) * 0.75 + 8.0,
                                                    1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[86]))->FUN_00a012d0(
            4002, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[59]))->GetFloat(4002) + reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[10]))->GetFloat(4002),
            1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[86]))->FUN_00a012d0(4016, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[11]))->GetFloat(4016), 1);
        ::g_pHudMainMenuInstance->m_pTiles[86]->Set(4003, 0);
        ::g_pHudMainMenuInstance->m_pTiles[60] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), kHitPoints)));
        ::g_pHudMainMenuInstance->m_pTiles[60]->Set(4001, iSafeZoneX3 * 2 + 10);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[60]))->FUN_00a012d0(
            4002, (float)(iScreenHeightX - iSafeZoneYY * 2) - reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[60]))->GetFloat(4016), 1);
        ::g_pHudMainMenuInstance->m_pTiles[60]->Set(4008, 1);
        ::g_pHudMainMenuInstance->m_pTiles[42] = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[60], (char *)(kTemplateLeftBracket), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[42]), 2);
        ::g_pHudMainMenuInstance->m_pTiles[1] = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[60], (char *)(kTemplateMeter), (::Tile *)(0));
        ::g_pHudMainMenuInstance->m_pTiles[1]->Set(iOriginalXTrait14, 20);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[1]))->FUN_00a012d0(4002, 41.0f, 1);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[1]), 3);
        ::g_pHudMainMenuInstance->m_pTiles[2] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[60], (char *)(kTemplateJustifyRightText3), (::Tile *)(0));
        ::g_pHudMainMenuInstance->m_pTiles[2]->Set(4001, 53);
        ::g_pHudMainMenuInstance->m_pTiles[2]->Set(4002, 8);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[2]), 0);
        ::g_pHudMainMenuInstance->m_pTiles[6] = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[60], (char *)(kTemplateCompassWindow), (::Tile *)(0));
        ::g_pHudMainMenuInstance->m_pTiles[3] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[6], (char *)(kTemplateCompassIconGroup), (::Tile *)(0));
        ::g_pHudMainMenuInstance->m_pTiles[3]->Set(4002, 30);
        ::g_pHudMainMenuInstance->m_pTiles[3]->Set(4013, 4);
        ::g_pHudMainMenuInstance->m_pTiles[4] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[6], (char *)("template_compass_icon_group"), (::Tile *)(0));
        ::g_pHudMainMenuInstance->m_pTiles[4]->Set(4002, 30);
        ::g_pHudMainMenuInstance->m_pTiles[4]->Set(4013, 3);
        ::g_pHudMainMenuInstance->m_pTiles[5] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[6], (char *)("template_compass_icon_group"), (::Tile *)(0));
        ::g_pHudMainMenuInstance->m_pTiles[5]->Set(4002, 10);
        ::g_pHudMainMenuInstance->m_pTiles[5]->Set(4013, 2);
        for (int l_e8 = 0; l_e8 < *((int *)&(::FUN_0043d4d0((int *)&((*reinterpret_cast<::SettingInt *>(&::g_011d32d0)))))); l_e8++)
        {
            Tile* l_ec =
                reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MenuStub*)::g_pHudMainMenuInstance)))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[5], (char *)("compass_npc_icon"), (::Tile *)(0));
        }
        for (int l_f0 = 0; l_f0 < 10; l_f0++)
        {
            Tile* l_f4 = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MenuStub*)::g_pHudMainMenuInstance)))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[4], (char *)("template_compass_icon_quest"), (::Tile *)(0));
        }
        pPlayerIcon =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MenuStub*)::g_pHudMainMenuInstance)))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[4], (char *)("template_compass_icon_player"), (::Tile *)(0));
        for (int l_f8 = 0; l_f8 < 10; l_f8++)
        {
            Tile* l_fc =
                reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MenuStub*)::g_pHudMainMenuInstance)))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[3], (char *)(kTemplateCompassIconMarker), (::Tile *)(0));
        }
        ::g_pHudMainMenuInstance->m_pTiles[61] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), kRadiationMeter)));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[61]))->FUN_00a012d0(
            4001, (float)(iScreenWidthC - iSafeZoneX3 * 2) - reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[61]))->GetFloat(4017) - 20.0,
            1);
        ::g_pHudMainMenuInstance->m_pTiles[61]->Set(4002, iSafeZoneYY * 2);
        ::g_pHudMainMenuInstance->m_pTiles[17] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[61]), "radiation_bracket")));
        ::g_pHudMainMenuInstance->m_pTiles[18] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[61]), "radiation_pointer")));
        ::g_pHudMainMenuInstance->m_pTiles[20] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[61]), "radiation_text")));
        ::g_pHudMainMenuInstance->m_pTiles[19] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[61]), "radiation_text_value")));
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((::g_pHudMainMenuInstance->m_pTiles[19]))->FUN_00a01350(4036, (char *)("+0"), 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((::g_pHudMainMenuInstance->m_pTiles[20]))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingString *>(&::g_011d21d8))))->GetMenuTitle()))), 1);
        ::g_pHudMainMenuInstance->m_pTiles[62] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "EnemyHealth")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[62]))->FUN_00a012d0(
            4001, (float)(iScreenWidthC / 2) - reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[62]))->GetFloat(4017) / 2.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[62]))->FUN_00a012d0(4002, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[60]))->GetFloat(4002) + 40.0, 1);
        ::g_pHudMainMenuInstance->m_pTiles[62]->Set(4008, 1);
        ::g_pHudMainMenuInstance->m_pTiles[62]->Set(4084, 2);
        ::g_pHudMainMenuInstance->m_pTiles[21] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[62], (char *)("template_enemy_health_bracket"), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[21]), 1);
        ::g_pHudMainMenuInstance->m_pTiles[21]->Set(4003, 1);
        ::g_pHudMainMenuInstance->m_pTiles[22] = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[62], (char *)("template_meter"), (::Tile *)(0));
        ::g_pHudMainMenuInstance->m_pTiles[22]->Set(iOriginalXTrait14, 171);
        ::g_pHudMainMenuInstance->m_pTiles[22]->Set(iTotalWidthTraitA, 240);
        ::g_pHudMainMenuInstance->m_pTiles[22]->Set(4002, 3);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[22]), 3);
        ::g_pHudMainMenuInstance->m_pTiles[22]->Set(4003, 1);
        ::g_pHudMainMenuInstance->m_pTiles[23] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[62], (char *)("template_justify_center_text"), (::Tile *)(0));
        ::g_pHudMainMenuInstance->m_pTiles[23]->Set(4001, 170);
        ::g_pHudMainMenuInstance->m_pTiles[23]->Set(4002, 35);
        ::g_pHudMainMenuInstance->m_pTiles[23]->Set(4026, 350);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[23]), 0);
        iQuestYAA = iSafeZoneYY * 2 + 170;
        ::g_pHudMainMenuInstance->m_pTiles[63] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "QuestReminder")));
        ::g_pHudMainMenuInstance->m_pTiles[63]->Set(4001, iSafeZoneX3 * 2 + 15);
        ::g_pHudMainMenuInstance->m_pTiles[63]->Set(4002, iQuestYAA);
        ::g_pHudMainMenuInstance->m_pTiles[13] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[63]), "QuestStages")));
        ::g_pHudMainMenuInstance->m_pTiles[14] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[63]), "QuestAdded")));
        for (int l_100 = 0; l_100 < 64; l_100++)
        {
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MenuStub*)::g_pHudMainMenuInstance)))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[14], (char *)("template_justify_left_text"), (::Tile *)(0));
        }
        for (int l_104 = 0; l_104 < 32; l_104++)
        {
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MenuStub*)::g_pHudMainMenuInstance)))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[13], (char *)("template_filled_checkbox"), (::Tile *)(0));
        }
        for (int l_108 = 0; l_108 < 32; l_108++)
        {
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MenuStub*)::g_pHudMainMenuInstance)))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[13], (char *)("template_justify_left_text"), (::Tile *)(0));
        }
        ::g_pHudMainMenuInstance->m_pTiles[64] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "Region_Location")));
        ::g_pHudMainMenuInstance->m_pTiles[64]->Set(4001, iSafeZoneX3 * 2 + 15);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[64]))->FUN_00a012d0(4002, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[60]))->GetFloat(4002) - 75.0, 1);
        ::g_pHudMainMenuInstance->m_pTiles[15] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[64], (char *)("template_justify_left_text"), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[15]), 0);
        ::g_pHudMainMenuInstance->m_pTiles[15]->Set(4003, 1);
        NiPoint3Stub kTextSize1 =
            ((::FontManagerStub *)(::FontManager::Instance()))->FUN_00a1b020(kTestHeight2, (int)reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[15]))->GetFloat(4025),
                                         reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[15]))->GetFloat(4026), 0);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[15]))->FUN_00a012d0(4002, kTextSize1.y, 1);
        ::g_pHudMainMenuInstance->m_pTiles[16] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[64], (char *)(kTemplateJustifyLeftText3), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[16]), 0);
        ::g_pHudMainMenuInstance->m_pTiles[16]->Set(4003, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[16]))->FUN_00a012d0(4002, kTextSize1.y, 1);
        ::g_pHudMainMenuInstance->m_pTiles[65] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "ReticleCenter")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[65]))->FUN_00a012d0(
            4001, (float)(iScreenWidthC / 2) - reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[65]))->GetFloat(4017) / 2.0 - 3.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[65]))->FUN_00a012d0(
            4002, (float)(iScreenHeightX / 2) - reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[65]))->GetFloat(4016) / 2.0 - 3.0, 1);
        ::g_pHudMainMenuInstance->m_pTiles[65]->Set(4008, 1);
        ::g_pHudMainMenuInstance->m_pTiles[65]->Set(4003, 1);
        ::g_pHudMainMenuInstance->m_pTiles[51] = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[65], (char *)(kTemplateReticleCenter), (::Tile *)(0));
        ::g_pHudMainMenuInstance->m_pTiles[51]->Set(4084, 1);
        ::g_pHudMainMenuInstance->m_pTiles[51]->Set(4003, 1);
        ::g_pHudMainMenuInstance->m_pTiles[66] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), kSneakMeter)));
        ::g_pHudMainMenuInstance->m_pTiles[66]->Set(4001, iScreenWidthC / 2);
        ::g_pHudMainMenuInstance->m_pTiles[66]->Set(4002, iSafeZoneYY * 2);
        ::g_pHudMainMenuInstance->m_pTiles[66]->Set(4008, 1);
        ::g_pHudMainMenuInstance->m_pTiles[66]->Set(4003, 0);
        ::g_pHudMainMenuInstance->m_pTiles[24] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[66]), kSneakNif)));
        ::g_pHudMainMenuInstance->m_pTiles[24]->Set(4009, 0);
        ::g_pHudMainMenuInstance->m_pTiles[67] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), kMessages)));
        iMessageOffsetX3 = -5;
        ::g_pHudMainMenuInstance->m_pTiles[67]->Set(4001, iMessageOffsetX3 + iSafeZoneX3 * 2);
        ::g_pHudMainMenuInstance->m_pTiles[67]->Set(4002, iSafeZoneYY * 2 + 25);
        ::g_pHudMainMenuInstance->m_pTiles[67]->Set(4008, 1);
        ::g_pHudMainMenuInstance->m_pTiles[25] = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[67], (char *)(kTemplateMessageIcon), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[25]), 6);
        ::g_pHudMainMenuInstance->m_pTiles[26] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[67], (char *)(kTemplateJustifyLeftText2), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[26]), 0);
        ::g_pHudMainMenuInstance->m_pTiles[26]->Set(4001, 130);
        ::g_pHudMainMenuInstance->m_pTiles[26]->Set(4002, 5);
        ::g_pHudMainMenuInstance->m_pTiles[26]->Set(4026, 320);
        ::g_pHudMainMenuInstance->m_pTiles[26]->Set(4013, 2);
        ::g_pHudMainMenuInstance->m_pTiles[26]->Set(4009, 0);
        ::g_pHudMainMenuInstance->m_pTiles[26]->Set(4003, 1);
        ::g_pHudMainMenuInstance->m_pTiles[27] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[67], (char *)(kTemplateMessageBracket), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[27]), 1);
        ::g_pHudMainMenuInstance->m_pTiles[68] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "Info")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[68]))->FUN_00a012d0(
            4001, (float)(iScreenWidthC / 2) - reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[68]))->GetFloat(4017) / 2.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[68]))->FUN_00a012d0(
            4002, (float)(iScreenHeightX - iSafeZoneYY * 2) - reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[68]))->GetFloat(4016) - 30.0,
            1);
        ::g_pHudMainMenuInstance->m_pTiles[68]->Set(4008, 1);
        ::g_pHudMainMenuInstance->m_pTiles[29] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[68]), kJustifyCenterHotrect)));
        ::g_pHudMainMenuInstance->m_pTiles[30] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[29]), kPCShortcutLabel)));
        ::g_pHudMainMenuInstance->m_pTiles[31] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[29]), kXboxButton)));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[29]), 0);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[29]))->FUN_00a012d0(FUN_00a01860("_x"),
                                                    reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[68]))->GetFloat(4017) / 2.0, 1);
        ::g_pHudMainMenuInstance->m_pTiles[32] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[68], (char *)("template_justify_center_text"), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[32]), 0);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[32]))->FUN_00a012d0(4001, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[68]))->GetFloat(4017) / 2.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[32]))->FUN_00a012d0(4026, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[68]))->GetFloat(4017), 1);
        ::g_pHudMainMenuInstance->m_pTiles[32]->Set(4002, 0);
        kTextSize1 = ((::FontManagerStub *)(::FontManager::Instance()))->FUN_00a1b020(kTestHeight, (int)reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[32]))->GetFloat(4025),
                                                  reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[32]))->GetFloat(4026), 0);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[32]))->FUN_00a012d0(4108, kTextSize1.y, 1);
        ::g_pHudMainMenuInstance->m_pTiles[33] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[68], (char *)(kTemplateJustifyCenterText3), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[33]), 0);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[33]))->FUN_00a012d0(4001, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[68]))->GetFloat(4017) / 2.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[33]))->FUN_00a012d0(4026, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[68]))->GetFloat(4017), 1);
        ::g_pHudMainMenuInstance->m_pTiles[33]->Set(4002, 65);
        ::g_pHudMainMenuInstance->m_pTiles[33]->Set(4009, 0);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((::g_pHudMainMenuInstance->m_pTiles[33]))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingString *>(&::g_011d2454))))->GetMenuTitle()))), 1);
        ::g_pHudMainMenuInstance->m_pTiles[33]->Set(4003, 0);
        ::g_pHudMainMenuInstance->m_pTiles[34] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[68], (char *)(kTemplateJustifyCenterText2), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[34]), 0);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[34]))->FUN_00a012d0(4001, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[68]))->GetFloat(4017) / 2.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[34]))->FUN_00a012d0(4026, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[68]))->GetFloat(4017), 1);
        ::g_pHudMainMenuInstance->m_pTiles[34]->Set(4002, 65);
        ::g_pHudMainMenuInstance->m_pTiles[34]->Set(4009, 0);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((::g_pHudMainMenuInstance->m_pTiles[34]))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingString *>(&::g_011d1f68))))->GetMenuTitle()))), 1);
        ::g_pHudMainMenuInstance->m_pTiles[34]->Set(4003, 0);
        iInfoRowY = 60;
        iInfoGapLeftAA = 25;
        iInfoPadLeft_ = 10;
        iInfoPadRightQ = 30;
        iInfoPadMid34 = 5;
        ::g_pHudMainMenuInstance->m_pTiles[35] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[68], (char *)(kTemplateJustifyRightText2), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[35]), 0);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[35]))->FUN_00a012d0(
            4001, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[68]))->GetFloat(4017) / 2.0 - iInfoGapLeftAA, 1);
        ::g_pHudMainMenuInstance->m_pTiles[35]->Set(4002, iInfoRowY);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[35]))->FUN_00a012d0(4009, DAT_011d979c, 1);
        ::g_pHudMainMenuInstance->m_pTiles[36] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[68], (char *)(kTemplateJustifyLeftText), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[36]), 0);
        ::g_pHudMainMenuInstance->m_pTiles[36]->Set(4001, iInfoPadLeft_);
        ::g_pHudMainMenuInstance->m_pTiles[36]->Set(4002, iInfoRowY);
        ::g_pHudMainMenuInstance->m_pTiles[37] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[68], (char *)(kTemplateJustifyRightText), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[37]), 0);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[37]))->FUN_00a012d0(
            4001, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[68]))->GetFloat(4017) - iInfoPadRightQ, 1);
        ::g_pHudMainMenuInstance->m_pTiles[37]->Set(4002, iInfoRowY);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[37]))->FUN_00a012d0(4009, DAT_011d979c, 1);
        ::g_pHudMainMenuInstance->m_pTiles[38] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[68], (char *)("template_justify_left_text"), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[38]), 0);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[38]))->FUN_00a012d0(
            4001, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[68]))->GetFloat(4017) / 2.0 + iInfoPadMid34, 1);
        ::g_pHudMainMenuInstance->m_pTiles[38]->Set(4002, iInfoRowY);
        ::g_pHudMainMenuInstance->m_pTiles[39] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[68], (char *)("template_info_seperator"), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[39]), 2);
        ::g_pHudMainMenuInstance->m_pTiles[69] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "Subtitles")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[69]))->FUN_00a012d0(
            4001, (float)(iScreenWidthC / 2) - reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[69]))->GetFloat(4017) / 2.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[69]))->FUN_00a012d0(4002,
                                                    reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[68]))->GetFloat(4002) -
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[69]))->GetFloat(4016) - 50.0,
                                                    1);
        ::g_pHudMainMenuInstance->m_pTiles[69]->Set(4008, 1);
        ::g_pHudMainMenuInstance->m_pTiles[28] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[69], (char *)(kTemplateJustifyCenterText), (::Tile *)(0));
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[28]), 0);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[28]))->FUN_00a012d0(4001, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[69]))->GetFloat(4017) / 2.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[28]))->FUN_00a012d0(4026, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[69]))->GetFloat(4017), 1);
        ::g_pHudMainMenuInstance->m_pTiles[70] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), kHokeys)));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[70]))->FUN_00a012d0(4001, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[59]))->GetFloat(4001) + 15.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[70]))->FUN_00a012d0(4002,
                                                    (float)(iScreenHeightX - iSafeZoneYY * 2) -
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[60]))->GetFloat(4016) -
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[70]))->GetFloat(4016) - 20.0,
                                                    1);
        ::g_pHudMainMenuInstance->m_pTiles[70]->Set(4008, 1);
        ::g_pHudMainMenuInstance->m_pTiles[40] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[70], (char *)("template_hotkey_selector"), (::Tile *)(0));
        reinterpret_cast<::HotkeyWheelDisplay *>((((HotKeyWheelStub*)::g_pHudMainMenuInstance->m_kMenuData)))->Initialize(::g_pHudMainMenuInstance->m_pTiles[40]);
        ::g_pHudMainMenuInstance->m_pTiles[41] =
            reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((pMenuXB))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[70], (char *)("template_justify_center_text"), (::Tile *)(0));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[41]))->FUN_00a012d0(4001, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[70]))->GetFloat(4017) / 2.0, 1);
        ::g_pHudMainMenuInstance->m_pTiles[41]->Set(4002, -50);
        ::g_pHudMainMenuInstance->m_pTiles[41]->Set(4003, 0);
        ::g_pHudMainMenuInstance->m_pTiles[71] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "XPMeter")));
        ::g_pHudMainMenuInstance->m_pTiles[71]->Set(4001, iScreenWidthC - iSafeZoneX3 * 2 - 390);
        ::g_pHudMainMenuInstance->m_pTiles[71]->Set(4002, iScreenHeightX - iSafeZoneYY * 2 - 280);
        ::g_pHudMainMenuInstance->m_pTiles[71]->Set(4103, iScreenHeightX - iSafeZoneYY * 2 - 280);
        ::g_pHudMainMenuInstance->m_pTiles[45] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[71]), "XPAmount")));
        ::g_pHudMainMenuInstance->m_pTiles[46] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[71]), "XPLabel")));
        ::g_pHudMainMenuInstance->m_pTiles[47] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[71]), "XPPointer")));
        ::g_pHudMainMenuInstance->m_pTiles[44] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[71]), "XPBracket")));
        ::g_pHudMainMenuInstance->m_pTiles[48] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[71]), "XPLastLevel")));
        ::g_pHudMainMenuInstance->m_pTiles[49] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[71]), "XPNextLevel")));
        ::g_pHudMainMenuInstance->m_pTiles[50] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[71]), "XPLevelUp")));
        ::g_pHudMainMenuInstance->m_pTiles[72] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "BreathMeter")));
        ::g_pHudMainMenuInstance->m_pTiles[72]->Set(4001, iScreenWidthC / 2);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[72]))->FUN_00a012d0(4002, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[66]))->GetFloat(4002) + 80.0, 1);
        ::g_pHudMainMenuInstance->m_pTiles[73] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "Explosive_positioning_rect")));
        ::g_pHudMainMenuInstance->m_pTiles[73]->Set(4001, iScreenWidthC / 2);
        ::g_pHudMainMenuInstance->m_pTiles[73]->Set(4002, iScreenHeightX / 2);
        for (int l_10c = 0; l_10c < 6; l_10c++)
        {
            Tile* l_110 = reinterpret_cast<::fnv_00a1ddb0::FUN_00a1ddb0_shell *>((((MenuStub*)::g_pHudMainMenuInstance)))->FUN_00a1ddb0(::g_pHudMainMenuInstance->m_pTiles[73], (char *)("template_explosive_indicator"), (::Tile *)(0));
        }
        ::g_pHudMainMenuInstance->m_pTiles[74] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "crippled_limb_indicator")));
        iLimbOffsetXQ = 200;
        iLimbOffsetYB = 100;
        fLimbScaleAC = 75.0f;
        ::g_pHudMainMenuInstance->m_pTiles[74]->Set(4001, iScreenWidthC - iSafeZoneX3 * 2 - iLimbOffsetXQ);
        ::g_pHudMainMenuInstance->m_pTiles[74]->Set(4002, iLimbOffsetYB + iSafeZoneYY * 2);
        ::g_pHudMainMenuInstance->m_pTiles[53] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[74]), "Head")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[53]))->FUN_00a012d0(4024, fLimbScaleAC, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[53]))->FUN_00a012d0(4017, fLimbScaleAC * 85.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[53]))->FUN_00a012d0(4016, fLimbScaleAC * 92.0 / 100.0, 1);
        ::g_pHudMainMenuInstance->m_pTiles[53]->Set(4001, 0);
        ::g_pHudMainMenuInstance->m_pTiles[53]->Set(4002, 40);
        ::g_pHudMainMenuInstance->m_pTiles[52] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[74]), "Face")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[52]))->FUN_00a012d0(4024, fLimbScaleAC, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[52]))->FUN_00a012d0(4017, fLimbScaleAC * 48.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[52]))->FUN_00a012d0(4016, fLimbScaleAC * 64.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[52]))->FUN_00a012d0(4001,
                                                    reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[53]))->GetFloat(4001) +
                                                        (reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[53]))->GetFloat(4017) -
                                                         reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[52]))->GetFloat(4017)) /
                                                            2.0,
                                                    1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[52]))->FUN_00a012d0(4002,
                                                    reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[53]))->GetFloat(4002) +
                                                        (reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[53]))->GetFloat(4016) -
                                                         reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[52]))->GetFloat(4016)) /
                                                            2.0 +
                                                        fLimbScaleAC * 16.0 / 100.0,
                                                    1);
        ::g_pHudMainMenuInstance->m_pTiles[54] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[74]), "Torso")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[54]))->FUN_00a012d0(4024, fLimbScaleAC, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[54]))->FUN_00a012d0(4017, fLimbScaleAC * 102.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[54]))->FUN_00a012d0(4016, fLimbScaleAC * 128.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[54]))->FUN_00a012d0(
            4001, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[53]))->GetFloat(4001) + fLimbScaleAC * -14.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[54]))->FUN_00a012d0(
            4002, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[53]))->GetFloat(4002) + fLimbScaleAC * 86.0 / 100.0, 1);
        ::g_pHudMainMenuInstance->m_pTiles[55] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[74]), "Left_Arm")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[55]))->FUN_00a012d0(4024, fLimbScaleAC, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[55]))->FUN_00a012d0(4017, fLimbScaleAC * 100.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[55]))->FUN_00a012d0(4016, fLimbScaleAC * 52.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[55]))->FUN_00a012d0(
            4001, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[54]))->GetFloat(4001) + fLimbScaleAC * 90.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[55]))->FUN_00a012d0(4002, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[54]))->GetFloat(4002), 1);
        ::g_pHudMainMenuInstance->m_pTiles[56] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[74]), "Right_Arm")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[56]))->FUN_00a012d0(4024, fLimbScaleAC, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[56]))->FUN_00a012d0(4017, fLimbScaleAC * 96.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[56]))->FUN_00a012d0(4016, fLimbScaleAC * 54.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[56]))->FUN_00a012d0(
            4001, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[54]))->GetFloat(4001) + fLimbScaleAC * -88.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[56]))->FUN_00a012d0(
            4002, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[54]))->GetFloat(4002) + fLimbScaleAC * -5.0 / 100.0, 1);
        ::g_pHudMainMenuInstance->m_pTiles[57] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[74]), "Left_Leg")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[57]))->FUN_00a012d0(4024, fLimbScaleAC, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[57]))->FUN_00a012d0(4017, fLimbScaleAC * 72.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[57]))->FUN_00a012d0(4016, fLimbScaleAC * 112.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[57]))->FUN_00a012d0(
            4001, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[54]))->GetFloat(4001) + fLimbScaleAC * 47.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[57]))->FUN_00a012d0(
            4002, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[54]))->GetFloat(4002) + fLimbScaleAC * 86.0 / 100.0, 1);
        ::g_pHudMainMenuInstance->m_pTiles[58] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[74]), "Right_Leg")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[58]))->FUN_00a012d0(4024, fLimbScaleAC, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[58]))->FUN_00a012d0(4017, fLimbScaleAC * 84.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[58]))->FUN_00a012d0(4016, fLimbScaleAC * 112.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[58]))->FUN_00a012d0(
            4001, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[54]))->GetFloat(4001) + fLimbScaleAC * -37.0 / 100.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[58]))->FUN_00a012d0(
            4002, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[54]))->GetFloat(4002) + fLimbScaleAC * 83.0 / 100.0, 1);
        ::g_pHudMainMenuInstance->m_pTiles[75] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "DDTIcon")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[75]))->FUN_00a012d0(4001,
                                                    reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[60]))->GetFloat(4001) +
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[60]))->GetFloat(4017) + 5.0,
                                                    1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[75]))->FUN_00a012d0(4002,
                                                    reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[59]))->GetFloat(4002) +
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[6]))->GetFloat(4002) - 16.0,
                                                    1);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[75]), 0);
        ::g_pHudMainMenuInstance->m_pTiles[75]->Set(4003, 0);
        ::g_pHudMainMenuInstance->m_pTiles[76] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "DDTIconEnemy")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[76]))->FUN_00a012d0(4001,
                                                    reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[62]))->GetFloat(4001) +
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[22]))->GetFloat(4001) - 32.0,
                                                    1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[76]))->FUN_00a012d0(
            4002, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[62]))->GetFloat(4002) + reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[22]))->GetFloat(4002),
            1);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[76]), 0);
        ::g_pHudMainMenuInstance->m_pTiles[76]->Set(4003, 1);
        ::g_pHudMainMenuInstance->m_pTiles[76]->Set(4084, 2);
        ::g_pHudMainMenuInstance->m_pTiles[82] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "DDTIcon")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[82]))->FUN_00a012d0(4001,
                                                    reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[60]))->GetFloat(4001) +
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[60]))->GetFloat(4017) + 5.0,
                                                    1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[82]))->FUN_00a012d0(4002,
                                                    reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[59]))->GetFloat(4002) +
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[6]))->GetFloat(4002) - 16.0,
                                                    1);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[82]), 0);
        ::g_pHudMainMenuInstance->m_pTiles[82]->Set(4003, 1);
        ::g_pHudMainMenuInstance->m_pTiles[83] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "DDTIconEnemyAP")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[83]))->FUN_00a012d0(4001,
                                                    reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[62]))->GetFloat(4001) +
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[22]))->GetFloat(4001) - 32.0,
                                                    1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[83]))->FUN_00a012d0(
            4002, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[62]))->GetFloat(4002) + reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[22]))->GetFloat(4002),
            1);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[83]), 0);
        ::g_pHudMainMenuInstance->m_pTiles[83]->Set(4003, 1);
        ::g_pHudMainMenuInstance->m_pTiles[83]->Set(4084, 2);
        ::g_pHudMainMenuInstance->m_pTiles[77] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "AmmoTypeLabel")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[77]))->FUN_00a012d0(4001,
                                                    reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[59]))->GetFloat(4001) +
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[12]))->GetFloat(4001) - 165.0,
                                                    1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[77]))->FUN_00a012d0(
            4002, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[59]))->GetFloat(4002) + reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[12]))->GetFloat(4002),
            1);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[77]), 0);
        ::g_pHudMainMenuInstance->m_pTiles[77]->Set(4003, 1);
        ::g_pHudMainMenuInstance->m_pTiles[78] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::Tile *)(((::TileMenu *)(::FUN_00a09030(1004)))), "HardcoreMode")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[78]))->FUN_00a012d0(4001, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[60]))->GetFloat(4001) + 150.0, 1);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[78]))->FUN_00a012d0(4002, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[60]))->GetFloat(4002), 1);
        ::fnv_00774800::FUN_00774800((::fnv_00774800::Tile *)(::g_pHudMainMenuInstance->m_pTiles[78]), 0);
        ::g_pHudMainMenuInstance->m_pTiles[78]->Set(4003, 1);
        ::g_pHudMainMenuInstance->m_pTiles[78]->Set(4008, 1);
        ::g_pHudMainMenuInstance->m_pTiles[79] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[78]), "Dehydration")));
        ::g_pHudMainMenuInstance->m_pTiles[79]->Set(4001, 0);
        ::g_pHudMainMenuInstance->m_pTiles[79]->Set(4002, 0);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[79]))->FUN_00a012d0(4024, fLimbScaleAC, 1);
        ::g_pHudMainMenuInstance->m_pTiles[79]->Set(4009, 0);
        ::g_pHudMainMenuInstance->m_pTiles[81] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[78]), "Hunger")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[81]))->FUN_00a012d0(4001, reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[79]))->GetFloat(4017) + 10.0, 1);
        ::g_pHudMainMenuInstance->m_pTiles[81]->Set(4002, 0);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[81]))->FUN_00a012d0(4024, fLimbScaleAC, 1);
        ::g_pHudMainMenuInstance->m_pTiles[81]->Set(4009, 0);
        ::g_pHudMainMenuInstance->m_pTiles[80] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[78]), "Sleep")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[80]))->FUN_00a012d0(4001,
                                                    reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[81]))->GetFloat(4017) + 10.0 +
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[79]))->GetFloat(4017) + 10.0,
                                                    1);
        ::g_pHudMainMenuInstance->m_pTiles[80]->Set(4002, 0);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[80]))->FUN_00a012d0(4024, fLimbScaleAC, 1);
        ::g_pHudMainMenuInstance->m_pTiles[80]->Set(4009, 0);
        ::g_pHudMainMenuInstance->m_pTiles[84] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[78]), "Rads")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[84]))->FUN_00a012d0(4001,
                                                    reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[81]))->GetFloat(4017) + 10.0 +
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[79]))->GetFloat(4017) + 10.0 +
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[80]))->GetFloat(4017) + 10.0,
                                                    1);
        ::g_pHudMainMenuInstance->m_pTiles[84]->Set(4002, 0);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[84]))->FUN_00a012d0(4024, fLimbScaleAC, 1);
        ::g_pHudMainMenuInstance->m_pTiles[84]->Set(4009, 0);
        ::g_pHudMainMenuInstance->m_pTiles[85] = ((::Tile *)(::tile_path_resolver::FUN_00a08b20((::tile_path_resolver::UITile *)(::g_pHudMainMenuInstance->m_pTiles[78]), "LMBs")));
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[85]))->FUN_00a012d0(4001,
                                                    reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[81]))->GetFloat(4017) + 10.0 +
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[79]))->GetFloat(4017) + 10.0 +
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[80]))->GetFloat(4017) + 10.0 +
                                                        reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[84]))->GetFloat(4017) + 10.0,
                                                    1);
        ::g_pHudMainMenuInstance->m_pTiles[85]->Set(4002, 0);
        reinterpret_cast<::FUN_00a012d0_t *>((::g_pHudMainMenuInstance->m_pTiles[85]))->FUN_00a012d0(4024, fLimbScaleAC, 1);
        ::g_pHudMainMenuInstance->m_pTiles[85]->Set(4009, 0);
        if (!reinterpret_cast<::FUN_00770070_Class *>((((MenuStub*)::g_pHudMainMenuInstance)))->HasAllTiles())
        {
            ::FUN_0040fbe0(
                );
            ::fnv_007037e0::FUN_007037e0();
        }
        if (reinterpret_cast<::TileListBoxCalls *>((pMenuTileN))->GetFloat(4007) == 6006.0 || reinterpret_cast<::TileListBoxCalls *>((pMenuTileN))->GetFloat(4007) == 102.0)
            reinterpret_cast<::FUN_00a012d0_t *>((pMenuTileN))->FUN_00a012d0(4013, fTileAlphaM, true);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((::g_pHudMainMenuInstance->m_pTiles[12]))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingString *>(&::g_011d4918))))->GetMenuTitle()))), 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((::g_pHudMainMenuInstance->m_pTiles[8]))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingString *>(&::g_011d3e8c))))->GetMenuTitle()))), 1);
        reinterpret_cast<::fnv_00a01350::FUN_00a01350_shell *>((::g_pHudMainMenuInstance->m_pTiles[2]))->FUN_00a01350(4036, (char *)(((const char *)(reinterpret_cast<::StartMenu *>(&((*reinterpret_cast<::SettingString *>(&::g_011d300c))))->GetMenuTitle()))), 1);
        ::g_pHudMainMenuInstance->m_iHudValueFirstAfterUpdateList = 856;
        ::g_pHudMainMenuInstance->m_iHudValueSecondAfterUpdateList =
            (int)(reinterpret_cast<::TileListBoxCalls *>((::g_pHudMainMenuInstance->m_pTiles[6]))->GetFloat(4017) / 2.0) - 35;
        ::g_pHudMainMenuInstance->m_iHudValueThirdAfterUpdateList = 70;
        pMenuTileN->Set(4003, 1);
        reinterpret_cast<::Callees *>((((MenuStub*)::g_pHudMainMenuInstance)))->FUN_00726070();
        ::fnv_00a04200::FUN_00a04200(false);
        NiPointer<NiSourceTexture> spCompassAlphaB(0);
        spCompassAlphaB = ::NiSourceTexture::Create(NiFixedString("Textures\\Interface\\HUD\\hud_compass_alphamap.dds"),
                                       (::NiTexture__FormatPrefs &)((*reinterpret_cast<::NiTextureFormatPrefs *>(&::DAT_011a9598))), true, false);
        ::g_pHudMainMenuInstance->m_pTiles[6]->vf20()->FUN_007700b0(spCompassAlphaB);
        reinterpret_cast<::FUN_007700d0_cls *>((::g_pHudMainMenuInstance->m_pTiles[6]->vf20()))->set(true);
        (*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011d9770)) = new NiNode(0);
        ThreeByThreeMatrix kRotZXB;
        ThreeByThreeMatrix kRotXYB;
        reinterpret_cast<::FUN_00524ac0_shell *>(&(kRotZXB))->FUN_00524ac0(1.5707964f);
        reinterpret_cast<::FUN_004a0c90_shell *>(&(kRotXYB))->FUN_004a0c90(1.5707964f);
        reinterpret_cast<::FUN_0043fa80_s *>((((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011d9770))).operator->()))->FUN_0043fa80(reinterpret_cast<::ThreeByThreeMatrix *>((void *)&(kRotZXB))->operator+(kRotXYB));
        reinterpret_cast<::FUN_00440490_shell *>((((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011d9770))).operator->()))->FUN_00440490(0.1f);
        reinterpret_cast<::FUN_004bc1f0_S *>((((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011d9770))).operator->()))->FUN_004bc1f0(380.0f, 0.0f, 0.0f);
        NiUpdateData kUpdateSceneY(0.0f, false, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011d9770))).operator->()))->FUN_00a59c60((int)&(kUpdateSceneY));
        (*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011d975c)) = ((::NiNode *)(reinterpret_cast<::CamBuilder *>((((MenuStub*)::g_pHudMainMenuInstance)))->FUN_0077ee50()));
        (*reinterpret_cast<::HUDEmptyStub * *>(&::g_011d96bc)) = new HUDEmptyStub;
        ::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1)->vfdc((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011d9770)), true);
        fShadowRadiusXB = reinterpret_cast<::Twin_0084d030 *>((((::NiBoundStub *)(reinterpret_cast<::FUN_0043d450_Owner *>((((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011d9770))).operator->()))->FUN_0043d450()))))->GetStoredFloatValue() * 3.0;
        reinterpret_cast<::SSN_b5 *>((::NiAdditionalGeometryData::GetShadowSceneNodeForIndex(1)))->FUN_00b5ca70((::Node_b5 *)(::NiNode *)((*reinterpret_cast<::NiPointer< ::NiNode> *>(&::g_011d9770))), fShadowRadiusXB);
        pBreathNodeYA = ((::NiNode *)(reinterpret_cast<::fnv_0056c7f0::Tile *>((::g_pHudMainMenuInstance->m_pTiles[72]))->FUN_0056c7f0()));
        pController27 = ((::NiTimeController *)(reinterpret_cast<::MyHost *>((((::NiNode *)(pBreathNodeYA->GetAt(0)))))->FUN_00a5c570((const ::MyRTTI *)(::NiRTTI *)(&(*reinterpret_cast<::NiRTTI *>(&::g_011f36ac))))));
        reinterpret_cast<::NiAVObject *>((pBreathNodeYA))->SetLocalRotation(-1.5707964f, 1.0f, 0.0f, 0.0f);
        NiUpdateData kUpdateBreath2(0.0f, true, false);
        reinterpret_cast<::FUN_00a59c60_cls *>((((::NiNode *)(pBreathNodeYA->GetAt(0)))))->FUN_00a59c60((int)&(kUpdateBreath2));
        if (pController27)
        {
            NiControllerManagerStub* l_114 = (NiControllerManagerStub*)pController27;
            ::g_pHudMainMenuInstance->m_pHudAnimationSequence = ((void *)(reinterpret_cast<::fnv_0047a520::Fn47a520 *>((l_114))->FUN_0047a520((::fnv_0047a520::NFSHelper *)&(const ::NiFixedString &)(NiFixedString("Forward")))));
            reinterpret_cast<::NiControllerManager *>((l_114))->DeactivateAllSequences(0.0f);
            if (::g_pHudMainMenuInstance->m_pHudAnimationSequence)
                reinterpret_cast<::NiControllerManager *>((l_114))->ActivateControllerSequence((::NiControllerSequence *)(::g_pHudMainMenuInstance->m_pHudAnimationSequence), 0, 1, 1.0f, 0.0f, (::NiControllerSequence *)(0));
        }
        reinterpret_cast<::Menu *>((pMenuXB))->SetMenuVisibility(1);
        FUN_0077e430(*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SettingFloat *>(&::g_011d9774)))))));
        ::fnv_00771700::FUN_00771700(5);
        reinterpret_cast<::ActorTaskManager *>((((::ATMStub *)(::FUN_00713d70()))))->WaitForTasksDuringRendering();
        return pMenuTileN;
    }
    else
    {
        if (pMenuXB && ((int)(reinterpret_cast<::Callees *>((pMenuXB))->FUN_00726070())))
            delete pMenuXB;
    }
    reinterpret_cast<::ActorTaskManager *>((((::ATMStub *)(::FUN_00713d70()))))->WaitForTasksDuringRendering();
    return 0;
}

class TESForm
{
  public:
    virtual ~TESForm();
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
    virtual void v34();
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9c();
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void vd4();
    virtual void vd8();
    virtual void vdc();
    virtual void ve0();
    virtual void ve4();
    virtual void ve8();
    virtual void vec();
    virtual void vf0();
    virtual void vf4();
    virtual void vf8();
    virtual void vfc();
    virtual bool IsActor();
};
class TESObjectREFR : public TESForm
{
};
class Actor : public TESObjectREFR
{
  public:
};
struct SubtitlePoint
{
    float x, y, z;
    SubtitlePoint();
};
class BSSoundHandleEx
{
  public:
    unsigned int soundID, unk04, unk08;
    ~BSSoundHandleEx();
};
struct SubtitleRecord
{
    char text[260];
    unsigned int timestamp;
    float duration;
    SubtitlePoint position;
    int visibility;
    SubtitleRecord();
};
void* __cdecl operator new(unsigned int);
template <class T> struct SubtitleArray
{
    void* table;
    T* buffer;
    unsigned int size, capacity;
    unsigned int Add(T& item);
};
struct SubtitleTimer
{
    unsigned int unk00, unk04, unk08, unk0c, unk10, timestamp, unk18, unk1c;
};
struct SubtitleSettingBool
{
    bool* Bool();
};
struct SubtitleSettingFloat
{
};
class SubtitleHUD : public Menu
{
  public:
    Tile* tiles[87];
    void* active;
    float seenLevel;
    char messages[8];
    unsigned int messageStart;
    SubtitleArray<SubtitleRecord*> subtitles;
    void* currentSubtitle;
    BSSoundHandleEx geigerSound;
    void* lastObject;
    int visibilityMenuMode, visibilityUserSettings, menuMode;
    char hotkeyWheel[52];
    bool scopeVisible;
    void* breathMeterAnimation;
    bool xpMeterFinishedMoving, forceObjectiveReminders;
    unsigned int killRegionDisplay;
    void* questList;
    int compassImageWidth, compassDisplayWidth, compassHalfAngle;
    void* currentEnemy;
    bool wasSneaking;
    SubtitleTimer timer;
    bool FUN_00774fd0(const char*, BSSoundHandleEx, SubtitlePoint, TESObjectREFR*, bool);
};
// @fnv 0x00774fd0
bool SubtitleHUD::FUN_00774fd0(const char* text, BSSoundHandleEx sound, SubtitlePoint position, TESObjectREFR* speaker,
                               bool persistent)
{
    bool added = false;
    Actor* actor = speaker && speaker->IsActor() ? dynamic_cast<Actor*>(speaker) : 0;
    if (text && (*(*reinterpret_cast<::SubtitleSettingBool *>(&::g_011d8928)).Bool() || (actor && ::FUN_008c1bc0((int)(actor)))))
    {
        SubtitleRecord* record = new SubtitleRecord;
        ::TaskQueueInterface::CopyStringToBuffer(record->text, 260, text);
        record->position = position;
        record->duration = ::FUN_00ad8b30((unsigned int *)&(sound)) / 1000.0;
        if (record->duration == 0.0)
            record->duration = strlen(text) * (*((float *)&(::FUN_00403e20((float *)&((*reinterpret_cast<::SubtitleSettingFloat *>(&::originalRuntimeFloatSetting1229)))))));
        if (persistent)
            record->visibility = 0x7fffffff;
        else if (speaker == (*reinterpret_cast<::TESObjectREFR * *>(&::_g_thePlayer)))
            record->visibility = 0;
        else if (speaker)
            record->visibility = 2;
        else
            record->visibility = 1;
        record->timestamp = reinterpret_cast<::fnv_00825c00::FUN_00825c00_shell *>(&(timer))->FUN_00825c00();
        reinterpret_cast<::FUN_00438690 *>(&(subtitles))->FUN_007cb2e0((unsigned int *)&(record));
        added = true;
    }
    return added;
}
