// Private declarations for MediaLocationController::Update.
// Existing class layouts are retained; only out-of-line declarations are added.
#ifndef FNV_MEDIALOCATIONCONTROLLER_UPDATE_DECLS_H
#define FNV_MEDIALOCATIONCONTROLLER_UPDATE_DECLS_H

// Unit-local header for fallout_shared/medialocationcontroller.cpp.
#include "fnv/decl/FORenderedMenu.h"
#include "fnv/decl/FUN_00595c80_shell.h"
#include "fnv/decl/FUN_00595cb0_shell.h"
#include "fnv/decl/FUN_00595cf0_shell.h"
#include "fnv/decl/FUN_00595d10_shell.h"
#include "fnv/decl/FUN_005fd3b0_shell.h"
#include "fnv/decl/LowProcess.h"
#include "fnv/decl/PlayerNearbyRefs.h"
#include "fnv/decl/ThisT.h"
#include "fnv/decl/fnv_00568cb0__FUN_00568cb0_shell.h"
#include "fnv/decl/fnv_008b8e90__FUN_008b8e90_shell.h"
#include "fnv/symbols_00453000.h"
#include "fnv/symbols_011dd000.h"
#include "fnv/symbols_011de000.h"
#ifndef FNV_MEDIALOCATIONCONTROLLER_UNIT_H
#define FNV_MEDIALOCATIONCONTROLLER_UNIT_H
#include "layout_support.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "layout_support.h"
class MediaLocationController;
class MediaSet;
enum FIGHT_REACTION
{
    FIGHT_REACTION_FIGHT_REACTION_NEUTRAL = 0,
    FIGHT_REACTION_FIGHT_REACTION_ENEMY = 1,
    FIGHT_REACTION_FIGHT_REACTION_ALLY = 2,
    FIGHT_REACTION_FIGHT_REACTION_FRIEND = 3,
    FIGHT_REACTION_FIGHT_REACTION_COUNT = 4
};
class MediaLocationController : public TESForm, public TESFullName
{
  public:
    MediaLocationController();
    // base TESForm at +0x0, size 24
    // base TESFullName at +0x18, size 12
    unsigned int m_fUpdateCooldown;  // +0x24, 4 bytes
    unsigned int m_uiFirstCounter;   // +0x28, 4 bytes
    unsigned int m_uiSecondCounter;  // +0x2C, 4 bytes
    unsigned int m_uiThirdCounter;   // +0x30, 4 bytes
    bool bIsActive;                  // +0x34, 1 bytes
    bool m_bCountWasNonzero;         // +0x35, 1 bytes
    bool m_bActorStateFlag;          // +0x36, 1 bytes
    bool m_bConditionWasTrue;        // +0x37, 1 bytes
    bool m_bConditionActive;         // +0x38, 1 bytes
    unsigned char layoutPadding39[3];
    float m_fLocationDistance;                     // +0x3C, 4 bytes
    unsigned int m_uiPerceivedActorCount;          // +0x40, 4 bytes
    unsigned int m_uiPreviousPerceivedActorCount;  // +0x44, 4 bytes
    FIGHT_REACTION m_eCurrentFightReaction;        // +0x48, 4 bytes
    char m_cMediaState;                            // +0x4C, 1 bytes
    unsigned char layoutPadding4D[3];
    MediaSet* m_pMediaSet;                     // +0x50, 4 bytes
    TESFullName m_kLocationName;               // +0x54, 12 bytes
    TESFaction* pFaction;                      // +0x60, 4 bytes
    FIGHT_REACTION m_eRequiredFightReaction;   // +0x64, 4 bytes
    TESObjectREFR* m_pReference;               // +0x68, 4 bytes
    int iFlags;                                // +0x6C, 4 bytes
    float m_fLowerWeightThreshold;             // +0x70, 4 bytes
    float m_fUpperWeightThreshold;             // +0x74, 4 bytes
    float m_fMediaSelectionValue;              // +0x78, 4 bytes
    float m_fUpdateInterval;                   // +0x7C, 4 bytes
    unsigned int m_uiShortDelay;               // +0x80, 4 bytes
    unsigned int m_uiLongDelay;                // +0x84, 4 bytes
    BSSimpleList<MediaSet*> m_kMediaSetList1;  // +0x88, 8 bytes
    BSSimpleList<MediaSet*> m_kMediaSetList2;  // +0x90, 8 bytes
    BSSimpleList<MediaSet*> m_kMediaSetList3;  // +0x98, 8 bytes
    BSSimpleList<MediaSet*> m_kMediaSetList4;  // +0xA0, 8 bytes
    BSSimpleList<MediaSet*> m_kMediaSetList5;  // +0xA8, 8 bytes
    BSSimpleList<MediaSet*> m_kMediaSetList6;  // +0xB0, 8 bytes
    virtual bool Load(TESFile* apFile);
    virtual void InitItem();
    void ProcessMediaSetList(BSSimpleList<MediaSet*>* apList);

  private:
    MediaSet* GetMediaSetFromList(BSSimpleList<MediaSet*>* apList);

  public:
    enum DEADREPFLAGS
    {
        DEADFACTION_CONDITIONAL_NEUTRAL,
        DEADFACTION_CONDITIONAL_ENEMY,
        DEADFACTION_CONDITIONAL_ALLY,
        DEADFACTION_CONDITIONAL_FRIEND,
        DEADFACTION_LOCATION,
        DEADFACTION_NONE
    };
    bool Update(bool abInCombat);
    void ResetFormData();
    void ClearData();
};
#endif
#ifndef FNV_MEDIASET_LOCAL_H
#define FNV_MEDIASET_LOCAL_H
#include "layout_support.h"
#include "TESForm.h"
#include "TESFullName.h"
class MediaSet : public TESForm, public TESFullName
{
  public:
    class MediaSetEntry
    {
      public:
        BSStringT<char> Name;
        float Attenuation;
        float Percent;
        MediaSetEntry();
    };
    enum MEDIASETTYPE
    {
        BATTLE = 0,
        LAYER_LOCATION = 1,
        LAYER_DUNGEON = 2,
        INCIDENTAL = 3,
        SETTYPE_COUNT = 4
    };
    unsigned int m_uiMediaValue1;
    unsigned int m_uiMediaValue2;
    unsigned int m_uiMediaValue3;
    bool bEffectFlag;
    bool m_bActorStateFlag;
    bool m_bCountWasNonzero;
    bool m_bConditionWasTrue;
    char m_cMediaState;
    TESFullName m_kFullName;
    MEDIASETTYPE Type;
    MediaSetEntry m_kMediaSetEntry1;
    MediaSetEntry m_kMediaSetEntry2;
    MediaSetEntry m_kMediaSetEntry3;
    MediaSetEntry m_kMediaSetEntry4;
    MediaSetEntry m_kMediaSetEntry5;
    MediaSetEntry m_kMediaSetEntry6;
    char m_cMediaFlag;
    float m_fMediaParameter1;
    float fSkillValueBonus;
    float m_fMediaParameter3;
    float m_fMediaValue;
    TESSound* m_pSound1;
    TESSound* m_pSound2;
    bool Update(unsigned int auiTime, bool abForce, MediaLocationController* apController);
};
#endif

class NiPoint3
{
  public:
    float x, y, z;
    NiPoint3 operator-(const NiPoint3& arOther) const;
      // canonical binding for SqrXYLength()
};
class TESObjectREFR : public TESForm
{
  public:
    unsigned char refData[0x50];
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
    virtual NiPoint3* GetPos() const;
};
class Actor : public TESObjectREFR
{
  public:
};
struct ActorCombatEntry
{
    Actor* pActor;
    bool m_bIsEnemy;
    bool m_bIsCombatTarget;
};
class MusicMarkerReference
{
  public:
    TESObjectREFR* m_pMarkerReference;
    void* m_pAudioMarkerData;
};
class PlayerCharacter : public Actor
{
  public:
};
class TESFaction : public TESForm
{
  public:
};
enum DEFAULT_OBJECT
{
    DEFAULT_OBJECT_PLAYER_FACTION = 6
};
class TESForm;
enum DEFAULT_OBJECT;
class BGSDefaultObjectManager
{
  public:
public:
    static ::TESForm *GetDefaultObjectByIndex(::DEFAULT_OBJECT);
};
class BSAudio
{
  public:
};
#endif
