// fallout/interface/menus/dialogmenu_decls.h: declares Tile, Interface, Menu, ListBoxBase, ListBox_int_ and more
#ifndef FNV_DIALOGMENU_DECLS_H
#define FNV_DIALOGMENU_DECLS_H

#include "fnv/decl/C764930ListMenu.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_0071aa60_class.h"
#include "fnv/decl/FUN_009611e0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a1d910_shell.h"
#include "fnv/decl/FUN_00a1dc70_shell.h"
#include "fnv/decl/IntListBox.h"
#include "fnv/decl/ListOwner.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00a01000.h"
#include "fnv/symbols_00a09000.h"
#include "layout_support.h"
#include "TESTopic.h"
class SoundPlaybackHandle
{
  public:
    unsigned int m_uiSoundResourceID;
    bool m_bLooping;
    unsigned char layoutPadding5[3];
    BSSoundHandle__ASSUMED_STATE eState;
    ~SoundPlaybackHandle();
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle&);
};

class Tile
{
  public:
    virtual ~Tile();
    void Set(int, int);
    void SetName(const char*);
    static float GetInterfaceScale();
};
class Interface
{
  public:
    enum enumMenus
    {
        Dialog = 1009
    };
    static bool GetSelectedTargetIndex(enumMenus menu);
public:
    static void SetHUDVisible(bool);
};

// Private declarations retain the PC field layout and the named virtual slots.
class Menu
{
  public:
    virtual ~Menu();
    virtual void AssignTileByID(int, Tile*);
    virtual void HandleLeftClickPress(unsigned int, Tile*);
    virtual void HandleSelection(int, Tile*);
    virtual void HandleMouseover(unsigned int, Tile*);
    virtual void HandleMouseoverTileAlt(unsigned int, Tile*);
    virtual void PostDragTileChange(unsigned int, Tile*, Tile*);
    virtual void PreDragTileChange(unsigned int, Tile*, Tile*);
    virtual void HandleActiveMenuClick(unsigned int, Tile*);
    virtual void OnClickHeld(unsigned int, Tile*);
    virtual void HandleMousewheel(unsigned int, Tile*);
    virtual void UpdateDialog();
    virtual bool HandleKeyboardInput(unsigned int);
    virtual unsigned int GetClass();
    virtual bool HandleMenuInput(int, float);
    virtual bool HandleControllerInput(int, Tile*);
    virtual void OnUpdateUserTrait(int);
    virtual void HandleControllerConnectOrDisconnect(bool);
    TileMenu* pMenu;
    BSSimpleList<Tile__TileTemplate*> m_kTileTemplateList;
    Tile* m_pMenuTile;
    int m_iModalMenuId, m_iSecondaryValue;
    bool m_bIsSpecial, m_bVisible;
    unsigned char layoutPadding1E[2];
    int m_iMenuId;
    Interface__FADE_STATE m_eFadeState;
    void SetMenuVisibility(bool);
};
class ListBoxBase
{
  public:
    virtual bool SetSelectedTile(Tile*);
    virtual Tile* GetSelectedTile();
    virtual Tile* HandleKeyboardInput(int);
    virtual bool IsParentMenu(Menu*);
    virtual void ScrollToHighlight();
    virtual Tile* GetItemTile(int, bool);
    virtual void vfn_18();
    virtual void Clear();
};
class ListBox_int_ : public ListBoxBase
{
  public:
    BSSimpleList<ListBoxItem_int_*> items;
    Tile* m_pListTile;
    Tile* m_pSelectedTile;
    Tile* m_pHighlightedTile;
    const char* pTemplateName;
    unsigned short m_usSelectedIndex;
    unsigned char layoutPadding1E[2];
    float m_fFirstListValue, m_fSecondListValue, m_fThirdListValue;
    unsigned short usFlags;
    unsigned char layoutPadding2E[2];
    void Initialize(Tile*, const char*);
};
class MenuTopic;
class TopicMenuController;
class MobileObject;
class ImageSpaceModifierInstanceDOF;
struct DialogMenuPoint2
{
    float x, y;
};
class DialogMenu : public Menu
{
  public:
    enum DialogState
    {
        eCameraZoomIn,
        eLoadSpeech,
        eSpeechIdle,
        ePlaySpeech,
        eCameraZoomOut,
        eServiceFadeOut
    };
    enum GoodbyeState
    {
        eInDialogue,
        eNaturalGoodbye,
        eForceGoodbye,
        eInvalidChoiceList
    };
    DialogState m_eDialogState;
    GoodbyeState m_eGoodbyeState;
    Tile* m_pTiles[4];
    ListBox_int_ m_kResponseListBox;
    TopicMenuController* pDialogueItem;
    SoundPlaybackHandle m_kActorProcessResult;
    MobileObject* m_pDialogueSpeaker;
    char m_cCurrentTopicLabel[128];
    bool m_bResponseStarted;
    unsigned char layoutPadding105[3];
    float m_fCameraTransitionTime;
    unsigned int m_uiDialogMenuFlags;
    DialogMenuPoint2 m_kDialogMenuPoint1, m_kDialogMenuPoint2, m_kDialogMenuPoint3;
    float m_fCameraTransitionAlpha;
    ImageSpaceModifierInstanceDOF* m_pDialogueDepthOfFieldModifier;
    bool m_bPauseRequested, bPaused;
    unsigned char layoutPadding132[2];
    DialogState m_eStateBeforePause;
    bool m_bServiceDialogue, m_bSuppressDialogueText, m_bServiceMenuRequested;
    unsigned char layoutPadding13B[1];
    static int ms_iDialogMenuValue;
    virtual bool HandleMenuInput(int button, float value);
    void SetCurrentTopic(MenuTopic* topic);
    DialogState BeginDialogueResponse(bool);
    void LoadTopicsList();
    static void Close();
    static Tile* Create(MobileObject*, TESTopic*, MobileObject*);
    virtual void UpdateDialog();
    virtual void HandleSelection(int, Tile*);
};
// These out-of-line getters are folded in the original executable. Use the
// established canonical decorated names for their shared implementations.
class NiNode;
class NiAVObject
{
  public:
};
class TESResponse
{
  public:
};
FNV_STATIC_ASSERT(sizeof(Menu) == 0x28);
FNV_STATIC_ASSERT(sizeof(ListBox_int_) == 0x30);
FNV_STATIC_ASSERT(sizeof(DialogMenu) == 0x13C);
FNV_STATIC_ASSERT(offsetof(DialogMenu, m_eGoodbyeState) == 0x2C);
FNV_STATIC_ASSERT(offsetof(DialogMenu, m_kResponseListBox) == 0x40);
#endif
