// fallout/interface/menus/loadingmenu_packet.h: declares BSThread, NiAVObject, NiNode, RgbaColor, NiGeometryData and more

#include "fnv/decl/DecalStub.h"
#include "fnv/decl/FUN_00408da0_Class.h"
#include "fnv/decl/FUN_00450410_Class.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00461070_shell.h"
#include "fnv/decl/FUN_005a7110_shell.h"
#include "fnv/decl/FUN_005a7130_shell.h"
#include "fnv/decl/FUN_005ec330_shell.h"
#include "fnv/decl/FUN_00678ce0_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/StartMenu.h"
#include "fnv/decl/fnv_0042ce10__FUN_0042ce10_shell.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_008648a0__FUN_008648a0_t.h"
#include "fnv/decl/fnv_00864980__FUN_00864980_shell.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_0040f000.h"
#include "fnv/symbols_0042f000.h"
#include "fnv/symbols_0043d000.h"
#include "fnv/symbols_00457000.h"
#include "fnv/symbols_00483000.h"
#include "fnv/symbols_004af000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_005a0000.h"
#include "fnv/symbols_005c2000.h"
#include "fnv/symbols_0070e000.h"
#include "fnv/symbols_0078a000.h"
#include "fnv/symbols_0078d000.h"
#include "fnv/symbols_00890000.h"
#include "fnv/symbols_011a0000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d0000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d8000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
class BSThread
{
  public:
    enum StackSize
    {
        StackSizeDefault = 0x4000
    };
    virtual ~BSThread();
    unsigned char _threadStorage[0x2c];
    BSThread();
    void SetName(const char*);
    void Initialize(StackSize, const char*, bool);
    void SetSchedulingPriority(unsigned int);
    void SetThreadPriority(int);
};

class InterfaceManager;
class NiAVObject
{
public:
    void SetLocalRotation(float, float, float, float);
};
class NiNode
{
  public:
};
class RgbaColor
{
  public:
};
class NiGeometryData
{
  public:
};
class NiProperty
{
  public:
};
class NiGeometry
{
  public:
};

class GlobalObject_0044f440
{
  public:
};
extern GlobalObject_0044f440 g_011da158, g_011da190, g_011da1a0;

enum ENUM_FORM_ID
{
    FormLoadScreen = 0x4b
};
class TESForm
{
  public:
    virtual void vfn_0();
    ENUM_FORM_ID GetFormType() const;
public:
    void NotifySaveLoadGameOfFormChange();
};
class TESFullName
{
  public:
public:
    void SetFullName(const char *);
};
class TESLoadScreen : public TESForm
{
  public:
    unsigned char pad[0x14];
    TESFullName fullName;
    bool MatchesFormLocation(TESForm*);
};
class BGSPerkEntry
{
  public:
    unsigned char pad[0x18];
    TESFullName fullName;
};
template <class T> class BSSimpleList
{
  public:
    T item;
    BSSimpleList* next;
    T& GetItem();
    BSSimpleList* GetNext();
    unsigned int ItemsInList();
    void AddTail(T const&);
};

class Tile
{
  public:
    void Set(int, int);
    void Set(int, float, bool);
    void Set(int, const char*, bool);
public:
    void Set(int, unsigned int);
public:
    static float GetInterfaceScale();
};
class BGSSaveLoadGame
{
  public:
};
class BGSQuestObjective
{
  public:
};
class GlobalObject_0078d900
{
  public:
    BGSQuestObjective* objective;
};
extern GlobalObject_0078d900 g_011da168;
extern float DAT_011da16c;
extern int DAT_011da170;
class SettingT_GameSettingCollection_
{
  public:
};
class GlobalObject_0040c150
{
  public:
    char storage[12];
};
extern GlobalObject_0040c150 g_011d1f8c, g_011d40f0;
void FUN_0078d670();

class GlobalObject2_0045cfe0
{
  public:
    char storage[12];
};

union SETTING_VALUE
{
    unsigned int u;
    int i;
    float f;
};
class GlobalObject_0045cfe0
{
  public:
    char storage[12];
};
extern GlobalObject_0045cfe0 g_011da108, g_011da124, g_011da138;
class ParentSpaceNode;
template <class T, unsigned int N> class BSSimpleArray
{
  public:
    unsigned int GetSize();
    void UpdateEntryValue(unsigned int, unsigned int);
    void Clear(bool);
    unsigned int Add(T&);
};
class NiFormArray
{
  public:
    TESForm*& FUN_00877a30(unsigned int);
};
class BGSMusicType
{
  public:
    class MusicTrack;
};
class ScriptVariableInfo;
class TESLoadScreenFlags
{
  public:
};

class TESQuest : public TESForm
{
  public:
    BGSQuestObjective* GetObjective(unsigned int);
public:
    void SetEnabled(bool);
};
class BGSLoadGameBuffer
{
  public:
};
class GlobalObject2_0040c150
{
  public:
    char storage[12];
};
void FUN_004581c0(bool);

class TESDataHandler
{
  public:
};
class OSGlobals;
class DurationData
{
  public:
};
class NavMeshInfo;
class LoadingMenu
{
  public:
    enum TileIndex
    {
        Tile0 = 0
    };
    unsigned char _padToTiles[0x4];
    void* unk04;
    unsigned char pad08[0x20];
    Tile* m_pTiles[38];
    int unkc0;
    int unkc4;
    int unkc8;
    int unkcc;
    char m_kFirstTileList[12];
    char m_kSecondTileList[12];
    char m_kThirdTileList[12];
    char m_kFourthTileList[12];
    char m_kFifthTileList[12];
    char m_aeMiscStatIdentifiers[172];
    char m_kLoadingScreenTip[8];
    char m_kLoadingScreenColor[16];
    BSSimpleList<BGSPerkEntry*> candidates;
    BSSimpleList<BGSPerkEntry*>* currentCandidate;
    unsigned char _padToTime[4];
    unsigned int nextTipTime;
    unsigned char _padToExtra[4];
    unsigned int extraCandidates;
    char _padToUsFlags_pad1ec[4];
    void* m_pAlternateTileShaderState;
    char m_kFirstDate[12];
    char m_kSecondDate[12];
    char m_kLoadScreenTextures[16];
    unsigned int m_uiLoadingScreenNumber;
    unsigned short m_usAdditionalFlags;
    unsigned short usFlags;

    void SetTileVisible(TileIndex, bool);
    static void HideTile();
    static void UpdateLoadingScreenThread();
    static void SetLoadingScreenVisible(int);
    void UpdateLoadingScreenTip();
    bool IsLoadScreenValid(TESLoadScreen*);
    void RefreshLoadingScreen();
    bool GetFloat(int);
    void SelectLoadScreens(BSSimpleArray<TESLoadScreen*, 1024>&);
    void CollectLoadScreens(BSSimpleArray<TESLoadScreen*, 1024>&);
    static void LoadGame(BGSLoadGameBuffer*);
    void UpdateLoadScreen(TESLoadScreen*, float, int);
    void FUN_0078b100(float, int);
    void UpdateTiles(float, int);
    void FadeSlideTiles(float, int);
    void UpdateLoadingTiles(float, int);
    void SetFloatFlag(int, bool);
    char m_kTileLayouts[912];
    unsigned int m_uiFirstStateValue;
    unsigned int m_uiSecondStateValue;
    int m_iStateFlags;
};

class BGSCameraPath
{
  public:
    BGSCameraPath* GetPrevPath();
};
