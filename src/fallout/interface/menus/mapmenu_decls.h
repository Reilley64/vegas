// fallout/interface/menus/mapmenu_decls.h: declares NiPoint3, NiPoint2, SettingT_GameSettingCollection_, TimeGlobal, InputManager and more
#ifndef MAPMENU_DECLS_H
#define MAPMENU_DECLS_H

#include <stddef.h>
#include "runtime/crt.h"
#include "fnv/decl/ButtonDevice.h"
#include "fnv/decl/Callees.h"
#include "fnv/decl/FUN_0045cd60_shell.h"
#include "fnv/decl/FUN_00569060_shell.h"
#include "fnv/decl/FUN_00588e40_shell.h"
#include "fnv/decl/FUN_0059e400_shell.h"
#include "fnv/decl/FUN_005e8d40_shell.h"
#include "fnv/decl/FUN_005e9300_Host.h"
#include "fnv/decl/FUN_0061f170_cls.h"
#include "fnv/decl/FUN_007700d0_cls.h"
#include "fnv/decl/FUN_00799dc0_class.h"
#include "fnv/decl/FUN_0083c7e0_shell.h"
#include "fnv/decl/FUN_0084e3a0_Class.h"
#include "fnv/decl/FUN_00877720_shell.h"
#include "fnv/decl/FUN_00a00f30_shell.h"
#include "fnv/decl/FUN_00a011f0_shell.h"
#include "fnv/decl/FUN_00a01230_shell.h"
#include "fnv/decl/FUN_00a012d0_t.h"
#include "fnv/decl/FUN_00a013d0_shell.h"
#include "fnv/decl/FUN_00a01440_shell.h"
#include "fnv/decl/FUN_00a03c90_shell.h"
#include "fnv/decl/FUN_00a07530_shell.h"
#include "fnv/decl/FUN_00a59d30_C.h"
#include "fnv/decl/FUN_00ad73b0_t.h"
#include "fnv/decl/FUN_00ad8830_shell.h"
#include "fnv/decl/FUN_00ad89e0_shell.h"
#include "fnv/decl/Fn575690.h"
#include "fnv/decl/HotkeyWheelDisplay.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/MyHack.h"
#include "fnv/decl/NiObjectNET.h"
#include "fnv/decl/Obj_009529d0.h"
#include "fnv/decl/S_00a04150_Class.h"
#include "fnv/decl/S_FUN_0045bc00.h"
#include "fnv/decl/SoundPlayback.h"
#include "fnv/decl/SoundWrapper.h"
#include "fnv/decl/StringHolder.h"
#include "fnv/decl/TileFloatList.h"
#include "fnv/decl/TutorialMessageGate718.h"
#include "fnv/decl/Vec3.h"
#include "fnv/decl/fnv_0056c7f0__Tile.h"
#include "fnv/decl/fnv_00575d70__FUN_00575d70_shell.h"
#include "fnv/decl/fnv_00578870__FUN_00578870_Class.h"
#include "fnv/decl/fnv_00825c00__FUN_00825c00_shell.h"
#include "fnv/decl/fnv_0093d660__TravelObject.h"
#include "fnv/decl/fnv_00a01350__FUN_00a01350_shell.h"
#include "fnv/decl/fnv_00a01b00__TileLoader.h"
#include "fnv/decl/fnv_00a03da0__FUN_00a03da0_shell.h"
#include "fnv/decl/fnv_00a07dc0__FUN_00a07dc0_shell.h"
#include "fnv/decl/fnv_00a09410__EvalValue.h"
#include "fnv/decl/fnv_00ad88f0__FUN_00ad88f0_h.h"
#include "fnv/symbols_00403000.h"
#include "fnv/symbols_00406000.h"
#include "fnv/symbols_00408000.h"
#include "fnv/symbols_00438000.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_00460000.h"
#include "fnv/symbols_004b7000.h"
#include "fnv/symbols_005b5000.h"
#include "fnv/symbols_00703000.h"
#include "fnv/symbols_00705000.h"
#include "fnv/symbols_00706000.h"
#include "fnv/symbols_00709000.h"
#include "fnv/symbols_0079a000.h"
#include "fnv/symbols_0079b000.h"
#include "fnv/symbols_0079c000.h"
#include "fnv/symbols_0079f000.h"
#include "fnv/symbols_007fa000.h"
#include "fnv/symbols_00867000.h"
#include "fnv/symbols_00a00000.h"
#include "fnv/symbols_00a09000.h"
#include "fnv/symbols_00a1c000.h"
#include "fnv/symbols_011c3000.h"
#include "fnv/symbols_011d1000.h"
#include "fnv/symbols_011d2000.h"
#include "fnv/symbols_011d3000.h"
#include "fnv/symbols_011d4000.h"
#include "fnv/symbols_011d5000.h"
#include "fnv/symbols_011da000.h"
#include "fnv/symbols_011de000.h"
#include "fnv/symbols_011f6000.h"
class NiNode;
class Tile;
class TileMenu;
class Menu;
class TESObjectREFR;
class TESWorldSpace;
class TESObjectCELL;
class TESForm;
class TESQuest;
class RegionObjectEntry;
class BGSNote;
class TESTopic;
class TESTopicInfo;
class DialogueItem;
class DialogueResponse;
class PathingPath;
class Character;
class BSAudio;
class FOPipboyManager;
class InterfaceManager;
class BSRenderedMenu;
class TESBoundObject;
class BGSQuestObjective;
class TESChallenge;
template <class T> class BSSimpleList
{
  public:
    BSSimpleList();
    ~BSSimpleList();
    T item;
    BSSimpleList* next;
    T& GetItem();
    BSSimpleList* GetNext();
    void RemoveAll();
    void AddTail(const T&);
};
template <class T, unsigned int N = 1024> class BSSimpleArray
{
  public:
    BSSimpleArray();
    ~BSSimpleArray();
    T* data;
    unsigned int size, capacity, grow;
    void Clear(bool);
    void Add(const T&);
};
template <class T> class BSStringT
{
  public:
    T* data;
    unsigned short len, capacity;
    BSStringT();
    ~BSStringT();
    int __cdecl PrintfString(const char*, ...);
    operator const T*() const;
};
class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3();
    NiPoint3(float, float, float);
    NiPoint3 operator*(float) const;
    static const NiPoint3 ZERO;
public:
    float ComputeMagnitude() const;
};
class NiPoint2
{
  public:
    NiPoint2();
    float x, y;
};
class SoundPlaybackHandle
{
  public:
    unsigned int id;
    bool assumeSuccess;
    unsigned int state;
    SoundPlaybackHandle();
    ~SoundPlaybackHandle();
    SoundPlaybackHandle& operator=(const SoundPlaybackHandle&);
    bool Pause();
public:
    bool IsPlaying() const;
public:
    bool IsValid() const;
};
union SETTING_VALUE;
class SettingT_GameSettingCollection_
{
  public:
    char pad[12];
    const char* String();
};
class INISettingCollection;
union SETTING_VALUE
{
    bool b;
    float f;
    const char* s;
};
template <class T> class SettingT
{
  public:
    char pad[12];
    SETTING_VALUE* Bool();
};
class TimeGlobal
{
  public:
};
class InputManager
{
  public:
};
class OSGlobals
{
  public:
};
class Interface
{
  public:
    enum enumMenus
    {
        Map = 0x3ff
    };
    static bool GetSelectedTargetIndex(enumMenus);
    FOPipboyManager* GetPipboyManager();
    static void __cdecl SetTileFormattedText(Tile*, int, const char*, ...);
};
class FORenderedMenu
{
  public:
    void StartBurst(float, float, float);
};
class FOPipboyManager : public FORenderedMenu
{
  public:
    bool IsUnk28Set();
    FORenderedMenu* FUN_00704370();
};
class TileListBoxCalls
{
  public:
    virtual Tile* Destroy(bool);
    virtual void Init(Tile*, const char*, Tile*);
    float GetFloat(int);
};
class Tile : public TileListBoxCalls
{
  public:
    virtual Tile* Destroy(bool);
    virtual void Init(Tile*, const char*, Tile*);
    void* fields[13];
    class Value
    {
      public:
    };
    void Set(int, int);
    void SetFlag8000(bool);
    static int GetTraitID(const char*);
    static float GetInterfaceScale();
public:
    void SetName(const char *);
public:
    void Set(int, unsigned int);
public:
    bool GetSpeechChallengeFailure();
};
class NiTexture;
class NiProperty;
struct NiTexture;
class TileShaderProperty
{
  public:
public:
    void FUN_00bb7a10(::NiTexture *);
};
class NiAVObject
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual void vfn_10();
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
};
class NiNode : public NiAVObject
{
  public:
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void RemoveObject(NiAVObject*);
    unsigned int FUN_0043b480();
    NiAVObject* GetAt(unsigned int);
};
class MapMarkerData
{
  public:
    bool IsTravelLocation();
public:
    bool GetVisible();
};
enum ENUM_FORM_ID
{
    kWorldSpace = 0x41
};
class TESForm
{
  public:
    virtual void vfn_00();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void vfn_0c();
    virtual ~TESForm();
    char data[12];
    ENUM_FORM_ID GetFormType() const;
    void NotifySaveLoadGameOfFormChange();
public:
    bool GetDisabled() const;
};
class ExtraRadioData;
class TESObjectREFR : public TESForm
{
  public:
    virtual void vfn_14();
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual void vfn_34();
    virtual void vfn_38();
    virtual void vfn_3c();
    virtual void vfn_40();
    virtual void vfn_44();
    virtual void vfn_48();
    virtual void vfn_4c();
    virtual void vfn_50();
    virtual void vfn_54();
    virtual void vfn_58();
    virtual void vfn_5c();
    virtual void vfn_60();
    virtual void vfn_64();
    virtual void vfn_68();
    virtual void vfn_6c();
    virtual void vfn_70();
    virtual void vfn_74();
    virtual void vfn_78();
    virtual void vfn_7c();
    virtual void vfn_80();
    virtual void vfn_84();
    virtual void vfn_88();
    virtual void vfn_8c();
    virtual void vfn_90();
    virtual void vfn_94();
    virtual void vfn_98();
    virtual void vfn_9c();
    virtual void vfn_a0();
    virtual void vfn_a4();
    virtual void vfn_a8();
    virtual void vfn_ac();
    virtual void vfn_b0();
    virtual void vfn_b4();
    virtual void vfn_b8();
    virtual void vfn_bc();
    virtual void vfn_c0();
    virtual void vfn_c4();
    virtual void vfn_c8();
    virtual void vfn_cc();
    virtual void vfn_d0();
    virtual void vfn_d4();
    virtual void vfn_d8();
    virtual void vfn_dc();
    virtual void vfn_e0();
    virtual void vfn_e4();
    virtual void vfn_e8();
    virtual void vfn_ec();
    virtual void vfn_f0();
    virtual void vfn_f4();
    virtual void vfn_f8();
    virtual void vfn_fc();
    virtual void vfn_100();
    virtual void vfn_104();
    virtual void vfn_108();
    virtual void vfn_10c();
    virtual void vfn_110();
    virtual void vfn_114();
    virtual void vfn_118();
    virtual void vfn_11c();
    virtual void vfn_120();
    virtual void vfn_124();
    virtual void vfn_128();
    virtual void vfn_12c();
    virtual void vfn_130();
    virtual void vfn_134();
    virtual void vfn_138();
    virtual void vfn_13c();
    virtual void vfn_140();
    virtual void vfn_144();
    virtual void vfn_148();
    virtual void vfn_14c();
    virtual void vfn_150();
    virtual void vfn_154();
    virtual void vfn_158();
    virtual void vfn_15c();
    virtual void vfn_160();
    virtual void vfn_164();
    virtual void vfn_168();
    virtual void vfn_16c();
    virtual void vfn_170();
    virtual void vfn_174();
    virtual void vfn_178();
    virtual void vfn_17c();
    virtual void vfn_180();
    virtual void vfn_184();
    virtual void vfn_188();
    virtual void vfn_18c();
    virtual void vfn_190();
    virtual void vfn_194();
    virtual void vfn_198();
    virtual void vfn_19c();
    virtual void vfn_1a0();
    virtual void vfn_1a4();
    virtual void vfn_1a8();
    virtual void vfn_1ac();
    virtual void vfn_1b0();
    virtual void vfn_1b4();
    virtual void vfn_1b8();
    virtual void vfn_1bc();
    virtual void vfn_1c0();
    virtual void vfn_1c4();
    virtual void vfn_1c8();
    virtual void vfn_1cc();
    virtual void vfn_1d0();
    virtual void vfn_1d4();
    virtual void vfn_1d8();
    virtual void vfn_1dc();
    virtual void vfn_1e0();
    virtual void vfn_1e4();
    virtual void vfn_1e8();
    virtual void vfn_1ec();
    virtual void vfn_1f0();
    virtual NiPoint3* GetPos();
    char refrData[0x60];
public:
    ::ExtraRadioData *GetExtraRadioData();
};
class Character : public TESObjectREFR
{
  public:
    char characterData[0x158];
    Character(bool);
};
class PlayerCharacter : public TESObjectREFR
{
  public:
};
class TESQuest
{
  public:
};
class TESWorldSpace : public TESForm
{
  public:
};
class TESObjectCELL : public TESForm
{
  public:
};
class RegionObjectEntry
{
  public:
    TESObjectREFR* GetReference(bool);
};
class TESDescription;
class TESTexture;
class BGSNote
{
  public:
    TESForm* FUN_005e9100();
    TESTopic* FUN_005e9240();
    TESBoundObject* FUN_005e92a0();
public:
    ::TESTexture *GetNoteTexture();
public:
    ::TESDescription *GetNoteDescription();
};
class TESTopicInfo
{
  public:
};
class DialogueResponse
{
  public:
};
class DialogueItem
{
  public:
    bool SelectDefaultResponseList();
    DialogueResponse* GetActiveResponse();
};
class Conversation
{
  public:
    char data[12];
    ~Conversation();
    Conversation(Character*, PlayerCharacter*, TESTopic*);
    bool FirstItem();
    void* Destroy(bool);
};
class BSAudio
{
  public:
    SoundPlaybackHandle GetSoundHandleByFormID(unsigned int, unsigned int);
    SoundPlaybackHandle GetSoundHandleByFilePath(const char*, unsigned int, void*);
    SoundPlaybackHandle GetSoundHandleByEditorID(const char*, unsigned int);
    static void EnableAudio();
    // Instance audio entry at 0x00ad85a0 is distinct from the static dialogue flag helper.
    float GetMusicVolume();
public:
    static void DeactivateAudio();
};
class FalloutRadio
{
  public:
    static bool SetRadioEnabled(bool);
    static bool SetRadioReferenceEnabled(TESObjectREFR*, bool);
};
template <class T> class ListBox
{
  public:
    ListBox();
    ~ListBox();
    virtual void vfn_00();
    virtual Tile* GetSelectedTile();
    char fields[44];
    T GetSelectedData();
    T GetSelectedData(Tile*);
    Tile* GetTileForData(T&);
    void Traverse(void (*)(Tile*, T), int, int);
    void Filter(bool (*)(T));
    void Initialize(Tile*, const char*);
    void SetSelectedTile(Tile*, bool);
    void ClearSelection(bool);
    void FUN_007a1a70();
    void FUN_007a1c90();
    void FUN_007a27f0();
    void FUN_007a36e0();
    void FUN_007a43a0();
    void FUN_007a50f0();
};
template <> void ListBox<TESQuest*>::ClearSelection(bool);
class Menu
{
  public:
    virtual ~Menu();
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void HandleSelection(int, Tile*);
    virtual void vfn_10();
    virtual void HandleMouseDown(int, Tile*);
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual unsigned int GetID();
    TileMenu* pMenu;
    char menuFields[32];
    Menu();
    void SetTileMenu(TileMenu*, bool);
    void SetMenuVisibility(bool);
};
class MapMenu : public Menu
{
  public:
    virtual void* Destroy(bool);
    virtual void vfn_04();
    virtual void vfn_08();
    virtual void HandleSelection(int, Tile*);
    virtual void vfn_10();
    virtual void HandleMouseDown(int, Tile*);
    virtual void vfn_18();
    virtual void vfn_1c();
    virtual void vfn_20();
    virtual void vfn_24();
    virtual void vfn_28();
    virtual void vfn_2c();
    virtual void vfn_30();
    virtual unsigned int GetID();
    int GetClass();
    Tile* m_pTiles[22];
    int m_iMapDisplayMode;
    Tile* m_pMapTile;
    float m_fMapRotation;
    bool m_bMapMenuActive;
    char pad8d[3];
    BGSNote* m_pSelectedNote;
    unsigned int m_uiMapState;
    BSSimpleList<SoundPlaybackHandle> m_kSoundList;
    BSSimpleArray<BSStringT<char> > SubtitlesToShow;
    BSSimpleList<SoundPlaybackHandle>* m_pkActiveSoundList;
    bool m_bMapListUpdatePending;
    char padbd[3];
    float m_fMapZoom;
    int m_iMapSelectionIndex;
    float m_fSavedMusicVolume;
    TESQuest* m_pSelectedQuest;
    RegionObjectEntry* m_pSelectedMapMarkerInfo;
    Tile* m_pSelectedMarkerTile;
    BSSimpleList<TESObjectREFR*> m_kMapMarkerList, LocalMapMarkerList;
    NiPoint2 m_kMapMinimumPoint, m_kMapMaximumPoint;
    TESForm* m_pCurrentMapSpace;
    NiPoint3 m_kPlayerWorldPosition;
    TESForm* m_pCurrentMapForm;
    TESWorldSpace* m_pCurrentWorldspace;
    bool m_bLocalMapMode;
    char pad111[3];
    TESObjectREFR* m_pFirstMapReference;
    TESObjectREFR* m_pSecondMapReference;
    TESObjectCELL* pAdjustNorthRotationCell;
    NiPoint2 m_kMapOffset;
    unsigned int m_uiMapMarkerCount;
    bool m_bNeedsMapUpdate;
    char pad12d[3];
    ListBox<TESQuest*> m_kQuestListBox;
    ListBox<BGSNote*> m_kNoteListBox;
    ListBox<TESObjectREFR*> m_kMapMarkerListBox;
    ListBox<BGSQuestObjective*> m_kObjectiveListBox;
    ListBox<TESChallenge*> m_kChallengeListBox;
    BSSimpleArray<Tile*> m_kMapMarkerTiles;
    MapMenu();
    static Tile* Create();
    void UpdateDialog();
    static void StopMapMenuSounds();
    static void SetMapPositionToPlayer();
    static void UpdateMapPosition();
    static void OpenMap();
    void SelectNote(BGSNote*);
    void SetMapDisplayMode(bool);
    TESObjectREFR* GetTeleportDestination(TESObjectREFR*, PathingPath*);
    TESWorldSpace* FUN_007984d0(NiPoint3);
    void RefreshMapMarkers();
    void UpdateMapObjectives();
    void SetFlag8000();
    void SetTileMenu(TileMenu*, bool);
    void SetMenuVisibility(bool);
public:
    void FUN_0079af30();
};
extern const double DAT_01074f68, DAT_010301a8;
class Calendar
{
  public:
    float GetGameTime();
    BSStringT<char> GetCurrentMonthName();
};
struct SystemLocaleState
{
    char fields[12];
    const char* String();
};
extern int DAT_011da354, DAT_011da358, DAT_011da35c;
extern bool DAT_011da36c, DAT_011da36d, DAT_011da36f, DAT_011da408;
extern unsigned int DAT_011da40c;
extern int DAT_011da360;
extern SettingT_GameSettingCollection_ DAT_011d4438, DAT_011d4960, DAT_011d33a8, DAT_011d4f54,
    DAT_011d3a2c, DAT_011d34f8, DAT_011d3684, DAT_011d4a38, DAT_011d48e8, DAT_011db458, DAT_011db37c;
extern SettingT_GameSettingCollection_* DAT_011a03e4[3];
int FUN_00720df0();
bool FUN_00798440();
class InterfaceManager
{
  public:
    class TutorialState
    {
      public:
    };
    char fields[0x4d4];
    TutorialState tutorials;
    float GetScaledValue();
    Tile* FUN_00586150();
};
void FUN_00798840();
void FUN_00798710();
extern "C" int sprintf_s(char*, size_t, const char*, ...);
template <class T> class NiPointer
{
  public:
    T* ptr;
    NiPointer& operator=(T*);
};
class TileImage : public Tile
{
  public:
    unsigned int imageFlags;
    NiPointer<NiAVObject> texture;
    void SetTexture(NiAVObject*);
};
#endif
